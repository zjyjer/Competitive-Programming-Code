#include <cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n<9)
		{
			printf("0\n");
			continue;
		}
		else if(n==9)
		{
			printf("8\n");
			continue;
		}
		else
		{
			printf("72");
			for(int i=10;i<n;i++)
				printf("0");
			printf("\n");
		}
	}
	return 0;
}