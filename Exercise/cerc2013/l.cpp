#include <cstdio>
int pow(int n)
{
	int ans = 1;
	while(n--)
		ans *= 2;
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int  n;
		scanf("%d", &n);
		printf("%d\n", pow(n) - 1);
	}
	return 0;
}
