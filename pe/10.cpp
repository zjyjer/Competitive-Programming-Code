#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000010;
bool vis[maxn];
int prime[maxn];
int cur = 0;
void init()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i < maxn; i++)
	{
		if(!vis[i])
			prime[++cur] = i;
		for(int j = 1; (j <= cur) && (i * prime[j] < maxn); j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	init();
	while(t--)
	{
		int n;
		cin >> n;
		long long ans = 0;
		for(int i = 1; i <cur; i++)
		{
			if(prime[i] <= n)
				ans += prime[i];
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}
