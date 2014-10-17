#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int minn = n / 2 + n % 2;
	int maxx = n;
	for(int i = minn; i <= maxx; i++)
	{
		if(i % m == 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
