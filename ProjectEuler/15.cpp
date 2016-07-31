#include <cstdio>

const int mod = 1000000007;
long long inv[1010] = {0};

void invtable()
{
	inv[1] = 1;
	for(int i = 2; i <= 1000; i++)
	{
		int t = mod / i;
		int k = mod - t * i;
		inv[i] = ((long long)i * t % mod) * t % mod;
		inv[i] = (inv[i] * inv[k] % mod) * inv[k] % mod;
	}
}

int c(int n, int m)
{
	long long ans = 1;
	for(int i = 0; i < m; i++)
		ans = ans * (n - i) % mod * inv[i+1] % mod;
	return ans;
}

int main()
{
	int cas;
	invtable();
	scanf("%d", &cas);
	while(cas--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		n += m;
		printf("%d\n", c(n, m));
	}
}
