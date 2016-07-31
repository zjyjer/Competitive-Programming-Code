#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

char s[100010];
int n, p;

int main()
{
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	if(p > n/2)
		p = n - p + 1;
	int ans = 0;
	int l = n, r = 0;
	for(int i = 1; i <= n / 2; i++)
	{
		if(s[i] != s[n - i + 1])
		{
			ans += std::min(abs(s[i] - s[n-i+1]), 26 - abs(s[i] - s[n - i + 1]));
			l = std::min(l, i);
			r = std::max(r, i);
		}
	}
	if(ans == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(r <= p) ans += p - l;
	else if(l < p && r > p) ans += (r - l) + std::min(p - l, r - p);
	else if(l >= p) ans += r - p;
	cout << ans << endl;
	return 0;
}
