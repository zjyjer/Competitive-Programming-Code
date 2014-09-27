#include <cstdio>
#include <cmath>
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		int n, b, q;
		bool flag = 0;
		scanf("%d %d %d", &n, &b, &q);
		if(q == 1)
		{
			while(b)
			{
				if(n == b)
				{
					flag = 1;
					break;
				}
				b /= 10;
			}
			if(flag)
				printf("1.00000\n");
			else printf("0.00000\n");
		}
		else if(q == 10 || q == 100 || q == 1000)
		{
			b = b * 100000;
			while(b)
			{
				if(n == b)
				{
					flag = 1;
					break;
				}
				b /= 10;
			}
			if(flag)
				printf("1.00000\n");
			else printf("0.00000\n");
		}
		else
			printf("%.5lf\n", (log(n + 1) - log(n)) / log(10.));
	}
	return 0;
}
