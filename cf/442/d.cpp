#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	freopen("a.in","r",stdin);
	int n;
	double a[110];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	double b=1.0;
	sort(a,a+n);
	
	double dp[110];
	for(int i=0;i<110;i++)
		dp[i]=1.0;
	dp[n-1]=a[n-1];
	b=1-a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		dp[i]=dp[i+1]*(1-a[i])+b*a[i];
		b*=(1-a[i]);
	}
	sort(dp,dp+n);
	//for (int i = 0; i < n; ++i)
	//{
//		cout << dp[i] << endl;
//	}
	cout <<fixed << setprecision(9) << dp[n-1] << endl;
	return 0;
}