#include <cstdio>
#include <iostream>
using namespace std;

long long sol(int n, int s)
{
	if(n%s==0)
		n--;
	int k = n/s;
	return (long long)s * k * (k+1)/2;
}

long long solve(int n)
{
	long long ans = sol(n,3) + sol(n,5) - sol(n, 15);
	return ans;
}
int main()
{
	int cas;
	cin >> cas;
	while(cas--)
	{
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}
