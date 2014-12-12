#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int a[1010];

int main()
{
	int n, l;
	cin >> n >> l;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int m = unique(a, a+n) - a;
	double ans = 0;
	ans = max(ans, a[0] * 1.0);
	ans = max(ans, (l - a[m - 1]) * 1.0);
	for(int i = 1; i < m; i++)
		ans = max(ans, (a[i] - a[i-1])/2.0);
	cout << fixed << setprecision(10) << ans <<endl;
	return 0;
}
