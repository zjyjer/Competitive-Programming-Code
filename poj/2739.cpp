#include <iostream>

const int maxn = 10000;
int vis[maxn + 10] = {0};
int pri[maxn];
int tot = 0;

int sum[maxn];

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

	sum[0] = 0;
	for (int i = 1; i <= tot; i++) {
		sum[i] = pri[i - 1] + sum[i - 1];
	}
	int n;
	while (std::cin >> n && n) {
		int ans = 0;
		int l = 1, r = 1;
		for (int l = 1; l <= tot; l++) {
			if (pri[l - 1] > n)
				break;
			while (sum[r] - sum[l - 1] < n)
				r ++;
			if (sum[r] - sum[l - 1] == n)
				ans ++;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
