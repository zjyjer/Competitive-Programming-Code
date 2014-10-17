#include <iostream>
using namespace std;

long long sol(long long n)
{
	return n * (n - 1) / 2 ;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	long long s = n / m;
	cout << sol(s + 1) * (n % m) + sol(s) * (m - n % m) << ' '<<sol(n - m + 1) << endl;
	return 0;
}
