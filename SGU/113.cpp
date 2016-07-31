#include <cstdio>
#include <cstring>
const int maxn=10000;
const int maxm=100010;
int prime[maxn];
bool vis[maxm+10];
int cur=0;
void pritable()
{
	memset(vis,0,sizeof(vis));
	for(long long i=2;i<=maxm;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			prime[cur++]=i;
			for(long long j=i*i;j<=maxm;j+=i)
				vis[j]=1;
		}
	}
}

bool is_prime(int n)
{
	for(int i=0;i<cur&&prime[i]<n;i++)
		if(n%prime[i]==0)
			return false;
	return true;
}
void solve(int m)
{
	bool flag=0;
	for(int i=0;i<cur&&prime[i]<m;i++)
		{
			if(m%prime[i]==0)
				{			
					int n=m/prime[i];
					if(is_prime(n))
						{
							flag=1;
							break;
						}
				}
		}
	if(flag) puts("Yes");
	else puts("No");
}
int main()
{
	int n;scanf("%d",&n);
	int m;
	pritable();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		solve(m);
	}
	return 0;
}