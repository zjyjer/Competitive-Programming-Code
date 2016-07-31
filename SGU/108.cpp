#include <cstdio>

bool vis[100]={0};
int ans[1000000];

int f(int n)
{
	int ans=n;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}

int main()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	int an=0;
	for(int i=1;i<=n;i++)
	{
		vis[f(i)%100]=1;
		if(!vis[i%100]) ans[an++]=i;
		vis[(i+99)%100]=0;
	}
	printf("%d\n",an);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&k);
		printf("%d ",ans[k-1]);
	}
	printf("\n");
}