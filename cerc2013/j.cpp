#include <cstdio>

long long f[5000];
long long p[5000];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, mod;
		scanf("%d %d", &n, &mod);
		f[0] = 1, f[1] = 1;
		for(int i = 2; i <= n; i++)
			f[i] = (f[i - 1] + f[i - 2]) % mod;
		for(int i = 1; i <= n; i++)
			scanf("%lld", &p[i]);
		for(int i = 1; i < n; i++)
		{
			for(int j = n; j > i; j--)
			{
				p[j] -= p[j - 1] * f[i];
				p[j] %= mod;
				if(p[j] < 0) p[j] += mod;
			}
		}
		p[n + 1] = 0;
		for(int i = n ; i > 0; i--)
		{
			for(int j = i + 1; j <= n + 1; j++)
			{
				p[j] += p[j-1] * f[i];
				p[j] %= mod;
				if(p[j] < 0) p[j] += mod;
			}
		}
		printf("%lld\n", p[n + 1]);
	}
	return 0;
}
