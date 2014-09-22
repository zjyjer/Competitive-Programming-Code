#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n)
{
	int ans = -1;
	for(int a = 0; a < n; a++)
	{
		int sqr = a * a;
		if(sqr % (n - a) == 0)
		{
			int b = n - a - (sqr / (n-a));
			b /= 2;
			int c = n - a - b;
			if(c > b && b > a && a + b > c && a * a + b * b == c * c)
			{
				int pro = a * b * c;
				ans = max(ans, pro);
			}
		}
	}
	if(ans <= 0) ans = -1;
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << solve(n) <<  endl;
	}
	return 0;
}
