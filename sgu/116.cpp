#include <cstdio>
#include <cstring>

const int maxn = 10010;
bool vis[maxn];
short prime[1300];
int supri[210];
short cnt[maxn][205];
short dp[maxn];
int tot = 0, tot2 = 0;

void init()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i <= maxn; i++)
	{
		if(!vis[i])
			prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 1; prime[prime[i]] <= maxn - 10 && i <= tot; i++)
	{
		supri[tot2++] = prime[prime[i]];
	}
}

void solve(int n)
{
	memset(cnt, 0, sizeof(cnt));
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < tot2; i++)
	{
		for(int V = supri[i]; V <= n; V++)
		{
			if(dp[V - supri[i]] + 1 < dp[V])
			{
				dp[V] = dp[V - supri[i]] + 1;
				for(int j = 0; j < tot2; j++)
					cnt[V][j] = cnt[V-supri[i]][j];
				cnt[V][i]++;
			}
		}
	}
	int index = 0;
	if(dp[n] > 3000)
		printf("0\n");
	else
	{
		printf("%d\n", dp[n]);
		for(int i = tot2 - 1; i >= 0; i--)
			if(cnt[n][i]!=0)
			{
				index = i;
				cnt[n][i]--;
				break;
			}
		printf("%d",supri[index]);
		for(int i = tot2 - 1; i >= 0; i--)
			if(cnt[n][i])
			{
				while(cnt[n][i]--)
					printf(" %d", supri[i]);
			}
		printf("\n");
	}
}

int main()
{
	init();
	int n;
	while(scanf("%d", &n)==1)
		solve(n);
	return 0;
}
