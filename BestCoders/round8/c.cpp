#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;
const int mod = 123456789;
int n, m, a[10010], b[10010];
int dp[10010][105];
int lowbit(int s)
{
	return s & (-s);
}
void add(int s, int x)
{
	while(s <= n)
	{
		a[s] += x;
		a[s] %= mod;
		s += lowbit(s);
	}
}
int sum(int s)
{
	int ret = 0;
	while(s > 0)
	{
		ret += a[s];
		ret %= mod;
		s -= lowbit(s);
	}
	return ret;
}
int main()
{
	while(scanf("%d %d", &n, &m)==2)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			b[i] = a[i];
		}
		sort(a+1, a+n+1);
		int size = unique(a+1, a+n+1) - (a+1);
		for(int i = 1; i <= n; i++)
			b[i] = upper_bound(a+1, a+n+1, b[i]) - a;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			dp[i][1] = 1;
			add(b[i], 1);
		}
		for(int j = 2; j <= m; j++)
		{
			memset(a, 0, sizeof(a));
			for(int i = 1; i <= n; i++)
			{
				dp[i][j] = sum(b[i] - 1);
				add(b[i], dp[i][j-1]);
			}
		}
		long long ret = 0;
		for(int i = 1; i <= n; i++)
			ret = (ret + dp[i][m]) % mod;
		cout << ret << "\n";
	}
	return 0;
}
