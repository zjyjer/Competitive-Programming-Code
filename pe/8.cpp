#include <iostream>
#include <cstring>
using namespace std;

char s[1010];
int dp[1010][1010];
int n, k;

int solve(char* s)
{
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
		dp[i][i] = s[i] - '0';
	for(int i = 1; i < k; i++)
		for(int j = 0; j + i < n; j++)
			dp[j][j+i] = dp[j][j+i-1] * (s[j+i] - '0');
	int ans = 0;
	for(int i = 0; i + k < n; i++)
	{
		ans = max(ans, dp[i][i+k-1]);
	}
	return ans;
}
		
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin.get();
		for(int i = 0; i < n; i++)
			s[i] = cin.get();
		cout << solve(s) << endl;
	}
	return 0;
}
