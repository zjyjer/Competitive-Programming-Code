#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n)
{
	int ans = -1;
	for(int a = 1; a < n; a++)
		for(int b = a + 1; b < n; b++)
		{
			int c = n - b - a;
			if(c > b && a + b > c && a * a + b * b == c * c)
				ans = max(ans, a * b * c);
		}
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
		cout << solve(n) << endl;
	}
	return 0;
}
