#include <cstdio>
#include <iostream>

const int mod = (int)1e9+7;
int cnt = 0;
int prime[1010];
long long factored (long long n, int pri)
{
	long long ans = n / pri;
	if (ans == 0)
		return 0;
	else
		return ans + factored(ans, pri);
}
long long fact[1010];
void solve(long long n)
{
	for (int i = 0; i < cnt; i++)
		fact[i] = factored(n, prime[i]);
}
long long sol(long long n, long long k)
{
	long long ans = 1;
	for (int i = 0; i < cnt; i++) {
		ans *= (fact[i] / k) + 1;
		ans %= mod;
	}
	return ans;
}
int main()
{
	//freopen("11802.in", "r", stdin);
	int __;
	std::cin >> __;
	bool vis[1010] = {0};
	for (int i = 2; i <= 1000; i++) {
		if (!vis[i]) {
			prime[cnt++] = i;
			for (int j = i * i; j <= 1000; j += i)
				vis[j] = 1;
		}
	}
	for (int cas = 1; cas <= __; cas++) {
		long long n, k;
		std::cin >> n >> k;
		solve(n);
		long long ans = (sol(n, k) - sol(n, k + 1) + mod) % mod;
		printf("Case %d: %lld\n", cas, ans);
	}
	return 0;
}