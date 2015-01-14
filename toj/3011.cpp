#include <cstdio>

int a[11] = {0};
int main()
{
	a[1] = 1; a[2] = 5; a[3] =11;
	for(int i = 4; i <= 10; i++)
	{
		a[i] = a[i-1]+a[i-2]*4 +a[i-3]*2;
		printf("%d\n",a[i]);
	}
	return 0;
}