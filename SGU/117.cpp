#include <cstdio>

int n,m,k;
int powmod(int a,int m)
{
	int ret=1;
	int tmp=a;
	while(m)
	{
		if(m&1)
			ret=ret*tmp%k;
		tmp=tmp*tmp%k;
		m>>=1;
	}
	return ret;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	int ans=0;
	int a;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(powmod(a,m)==0)
			ans++;
		//printf("%d\n",powmod(a,m));
	}
	printf("%d\n",ans);
	return 0;
}