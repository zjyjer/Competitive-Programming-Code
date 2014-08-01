#include <cstdio>
int f[11];

int c(int n,int k)
{
	int ret=1;
	for(int i=1;i<=k;i++)
		ret=ret*(n-i+1)/i;
	return ret;
}
int main()
{
	f[0]=1;
	for(int i=1;i<=10;i++)
		f[i]=i*f[i-1];
	int n,k;
	scanf("%d %d",&n,&k);
	if(k>n)
	{
		printf("0");
		return 0;
	}
	else printf("%d\n",f[k]*c(n,k)*c(n,k));
}