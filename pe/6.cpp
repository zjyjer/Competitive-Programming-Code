#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		cout << n * (n+1) / 2 * (3*n*n - n - 2) / 6 << endl;
	}
	return 0;
}
