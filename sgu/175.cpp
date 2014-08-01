#include <cstdio>

int dfs(int n,int m)
{
	//printf("%d %d\n",n,m);
	if(n==1)
		return m;
	int k=n/2;
	if(m>k)
		return dfs(n-k,n+1-m);
	else return n-k+dfs(k,k+1-m);
}
int main()
{
	int n,m;
	int ans;
	while(scanf("%d %d",&n,&m)==2)
	{
		ans=dfs(n,m);
	printf("%d\n",ans);
}
}