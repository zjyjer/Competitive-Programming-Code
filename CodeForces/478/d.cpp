#include <iostream>
using namespace std;

const int mod = 1000000007;
int dp[200010];

int main()
{
	int r, g;
	long long ans = 0;
	cin >> r >> g;
	dp[0] = 1;
	for(int i = 1; i < 1000; i++)
	{
		int sum = i * (i + 1) / 2;
		if(sum > r + g)
		{
			cout << ans << endl;
			break;
		}
		for(int j = r; j >= 0; j--)
		{
			if(sum - j > g) dp[j] = 0;
			if(j >= i) dp[j] = (dp[j] + dp[j - i]) % mod;	
		}
		ans = 0;
		for(int j = 0; j <= r; j++)
		{
			ans += dp[j];
			if(ans > mod) ans -= mod;
		}
	}
	return 0;
}
