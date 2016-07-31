#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	if(n==2)
	{
		printf("2 2\n3 1 4\n");
		return 0;
	}
	printf("%d",n);

	for(int i=3;i<=n;i++)
		for(int j=n-i+3;j<=n;j++)
			//printf(" (%d,%d)",i,j);
			printf(" %d",(i-1)*n+j);
		
		printf("\n");
		int m=n+1;
		int t=101;
		printf("%d",t);t+=2;
		for(int i=2;i<=n;i++)
			printf(" %d",i*n+2-i);
		printf("\n");
		while(m>2)
		{
			printf("%d",t);
			t+=2;	
			for(int i=1;i<m;i++)
				printf(" %d",(n-1)*i+m-n);
			printf("\n");	
			m--;
		}
		
		return 0;
	}
