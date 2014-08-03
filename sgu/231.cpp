#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[1000100];
int prime[80000];
int sol[80000];
int cur;

int main()
{
	cur=0;
	memset(vis,0,sizeof(vis));
	for(long long i=2;i<=1000000;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			prime[cur++]=i;
			for(long long j=i*i;j<=1000000;j+=i)
				vis[j]=1;
		}
	}
	int n;
	scanf("%d",&n);
	int ans=0,tmp=0;
	for(int i=0;i<cur;i++)
	{
		if(2+prime[i]>n)
			break;
		int loc=lower_bound(prime,prime+cur,2+prime[i])-prime;
		if(prime[loc]==2+prime[i])
		{
			ans++;
			sol[tmp++]=prime[i];
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<tmp;i++)
		printf("2 %d\n",sol[i]);
}