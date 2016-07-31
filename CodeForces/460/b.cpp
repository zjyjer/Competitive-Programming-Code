#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int f(long long x)
{
	int sum = 0;
	while(x)
	{
		sum += x%10;
		x /= 10;
	}
	return sum;
}

long long cal(long long x, int n)
{
	long long ret = 1;
	while(n--)
		ret *= x;
	return ret;
}

int main()
{
	int a, b, c;
	vector<long long> g;
	while(cin >> a >> b >> c)
	{
		g.clear();
		int ans = 0;
		for(int i = 1; i <=81; i++)
		{
			long long x = cal((long long)i, a) * b + c;
			if(f(x) == i && x <1e9)
			{
				g.push_back(x);
				ans++;
			}
		}
		cout << ans << endl;
		for(int i = 0; i < g.size(); i++)
			cout << g[i] << " ";
		cout << endl;
	}
	return 0;
}
