#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		int n;
		scanf("%d", &n);
		double k = 0.0;
		double tmp;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf", &tmp);
			k += tmp;
		}
		int tt;
		for(int i = 0; i < n; i++)
			scanf("%d", &tt);
		printf("%.6f\n", (n + 1) / k);
	}
	return 0;
}
