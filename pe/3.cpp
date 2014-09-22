#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010;
int vis[maxn];
long long prime[maxn];
int cur;

void init()
{
	memset(vis, 0, sizeof(vis));
	cur = 0;
	for(int i = 2; i < maxn; i++)
	{
		if(!vis[i])
			prime[++cur] = i;
		for(int j = 1; (j <= cur) && (i * prime[j] < maxn); j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j]==0) break;
		}
	}	
}

long long solve(long long n)
{
	long long ans = 1;
	for(int i = 1; i <= cur; i++)
	{
		if(n == 1)
			break;
		if(n % prime[i] == 0)
		{
			ans = max(ans, prime[i]);
		}
		while(n % prime[i] == 0)
			n /= prime[i];
	}
	if(n != 1)
		ans = max(n, ans);
	return ans;
}

int main()
{
	init();
	int cas;
	cin >> cas;
	while(cas--)
	{
		long long n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}
