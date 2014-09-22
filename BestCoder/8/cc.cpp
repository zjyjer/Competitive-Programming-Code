#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
const long long mod = 123456789;
int n, m, a[10010], b[10010];
int dp[10010][110];
int lowbit(int s)
{
	return s & (-s);
}

void add(int s, int x)
{
	while(s<=n)
	{
		a[s] += x;
		a[s]%=mod;
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
	return (int)ret;
}
int main()
{
	while(scanf("%d %d", &n, &m)==2)
	{
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			scanf("%d", a+i);
			b[i+1] = a[i];
		}
		sort(a, a+n);
		int size = unique(a, a+n) - a;
		for(int i = 1; i <= n; i++)
			b[i] = lower_bound(a, a+n, b[i]) - a + 1;
		memset(a, 0, sizeof(a));
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
				dp[i][j] = sum(b[i]-1);
				if(i < j) dp[i][j] = 0;
				add(b[i], dp[i][j-1]);
			}
		}
		long long ret = 0;
		for(int i = 1; i <= n; i++)
			ret = (ret + dp[i][m])% mod;
		cout << ret << endl;
	}
	return 0;
}
