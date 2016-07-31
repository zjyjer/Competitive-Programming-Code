#include <cstdio>
#include <cmath>

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int m=sqrt(n+0.5);
		int ans=n;
		for(int i=2;i<=m;i++)
		{
			if(n%i==0)
				ans=ans/i*(i-1);
			while(n%i==0)
				n/=i;
		}
		if(n>1)
			ans=ans/n*(n-1);
		printf("%d\n",ans);
	}
	return 0;
}