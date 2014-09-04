#include <iostream>
#include <algorithm>
using namespace std;

int a[100010];
int main()
{
	int n;
	cin >> n;
	a[0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	long long ans = a[0], cur = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i]-a[i-1] > cur)
		{
			ans += abs(cur-a[i]+a[i-1]);
			a[i-1] = a[i]-cur;
		}
		cur += (a[i-1]-a[i]);
	}
	cout << ans << endl;
	return 0;
}
