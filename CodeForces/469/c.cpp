#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n < 4)
	{
		puts("NO");
		return 0;
	}
	if(n % 2 == 0)
	{
		puts("YES");
		puts("4 * 3 = 12");
		puts("12 * 2 = 24");
		puts("24 * 1 = 24");
		for(int i = 5; i <= n; i+=2)
			printf("%d - %d = 1\n",i + 1, i);
		for(int i = 5; i <= n - 2; i+=2)
			puts("1 * 1 = 1");
	}
	else
	{
		puts("YES");
		puts("5 + 3 = 8");
		puts("1 - 2 = -1");
		puts("4 + -1 = 3");
		puts("3 * 8 = 24");
		for(int i = 6; i <= n; i+=2)
			printf("%d - %d = 1\n",i + 1, i);
		for(int i = 6; i <= n - 2; i+=2)
			puts("1 * 1 = 1");
	}
	if(n!=4 && n!=5)
	puts("24 * 1 = 24");
	return 0;
}
