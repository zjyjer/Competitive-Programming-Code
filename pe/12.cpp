#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000010;
int prime[maxn];
int cur = 0;
bool vis[maxn];
int val[maxn];
int step = 0;

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

int divisor(int n)
{
	step = 0;
	memset(val, 0, sizeof(val));
	for(int i = 1; i <= cur; i++)
	{
		if(n == 1)
			break;
		if(n % prime[i] == 0)
			step++;
		while(n % prime[i] == 0)
		{
			val[step]++;
			n /= prime[i];
		}
	}
	int ans = 1;
	for(int i = 1; i <= step; i++)
		ans *= (val[i] + 1);
	return ans;
}
int main()
{
	init();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		n = n * (n + 1 ) / 2;
		int k = divisor(n);
	}
	return 0;
}
