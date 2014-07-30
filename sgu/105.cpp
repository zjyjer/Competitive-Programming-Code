#include <cstdio>

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int k=n/3*2;
		if(n%3!=0)
			k+=(n%3-1);
		printf("%d\n",k);
	}
	return 0;
}
