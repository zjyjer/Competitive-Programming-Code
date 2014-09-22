#include <cstring>
#include <iostream>
using namespace std;

const int maxn=1000100;
int cur = 0;
int prime[maxn];
bool vis[maxn];
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
	init();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << prime[n] << endl;
	}
	return 0;
}
