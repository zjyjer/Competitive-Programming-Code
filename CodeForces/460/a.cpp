#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		int ans = 0;
		while(n >=  m)
		{
			ans += (n/m)*m;
			n = n/m + n%m;
		}
		ans += n;
		cout << ans << endl;
	}
	return 0;
}
