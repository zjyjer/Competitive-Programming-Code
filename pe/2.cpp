#include <iostream>
using namespace std;

long long fib[100];
int cur = 0;

int main()
{
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i <= 80; i++)
		fib[i] = fib[i-1] + fib[i-2];
	int cas;
	cin >> cas;
	while(cas--)
	{
		long long n;
		cin >> n;
		long long sum = 0;
		for(int i = 2; i <= 80; i += 3)
		{
			if(fib[i] >= n)
				break;
			sum += fib[i];
		}
		cout << sum << "\n";
	}
	return 0;
}
