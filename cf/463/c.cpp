#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[2010][2010];
long long  dp[2010][2010];
long long sum1[4010],sum2[4010];
pair<int, int> v[2];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&a[i][j]);
			sum1[i+j] += a[i][j];
			sum2[i-j+n] += a[i][j];
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			dp[i][j] = sum1[i+j] + sum2[i-j+n] - a[i][j];
	long long s[2] = {0, 0};
	v[0] = make_pair(1,1);
	v[1] = make_pair(1,2);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j] > s[(i+j)&1])
			{
				s[(i+j)&1] = dp[i][j];
				v[(i+j)&1] = make_pair(i+1,j+1);
			}
		}
	cout << s[0] + s[1] << endl;
	cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
	return 0;
}
