#include <iostream>
#include <algorithm>
#define debug(x) std::cout << #x << ' ' << x << std::endl;
bool check[2010] = {0};
int prime[1010];
int phi[2010];

void phitable(int n)
{
	phi[1] = 1;
	int tot = 0;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < tot; j++) {
			if (i * prime[j] > n) break;
			check[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}
int main()
{
	phitable(1001);
	int testcase;
	std::cin >> testcase;
	for (int cas = 1; cas <= testcase; cas++) {
		int N;
		std::cin >> N;
		int ans = 0;
		for (int i = 1; i <= N; i++)
			ans += phi[i];
		std::cout << cas << ' ' << N << ' ' << 2 * ans + 1 << std::endl;
	}
	return 0;
}
