#include <cstdio>

const int maxn = 1000000;
int vis[maxn + 10] = {0};
int pri[maxn];
int tot = 0;

int main()
{
	for (int i = 2; i < maxn; i++) {
		if (!vis[i])
			pri[tot++] = i;
		for (int j = 0; j < tot && i * pri[j] < maxn; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	
	int n;
	while (scanf("%d" , &n) && n) {
		for (int i = 3; i < tot; i++) {
			if (!vis[i] && !vis[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}	
	}
	return 0;
}
