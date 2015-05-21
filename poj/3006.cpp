#include <iostream>
#include <algorithm>

const int maxn = 1000000;
int vis[maxn + 10] = {0};
int pri[maxn];
int tot = 0;

int main()
{
	for (int i = 2; i < maxn; i++) {
		if (!vis[i])
			pri[tot++] = i;
		for (int j = 0; j < tot && i * pri[j] <= maxn; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}

	int a, d, n;
	while (std::cin >> a >> d >> n && a && d && n) {
		int cur = 1;
		int idx = std::lower_bound(pri, pri + tot, a) - pri;
		for (int i = idx; i < tot; i++) {
			if ((pri[i] - a) % d == 0 && cur++ == n) {
				std::cout << pri[i] << std::endl;
				break;
			}
		}
	}
	return 0;
}
