#include <iostream>
using namespace std;

long long x, y, a0;

long long gcd (long long x, long long y)
{
	if (x > y)
		swap(x,y);
	if(x == 0)
		return y;
	else return gcd(y%x, x);
}
int main()
{
	while(cin >> x >> y >> a0)
	{
		long long k = y / (x - 1);
		long long g = gcd(k, a0);
		k /= g, a0 /= g;
		
	}
}