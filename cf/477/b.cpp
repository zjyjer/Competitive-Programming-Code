#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	cout << k * (6 * n - 1) << endl;
	for(int i = 0; i < n; i++)
		cout << (6 * i + 1) * k << ' ' << (6 * i + 2) * k << ' ' << (6 * i + 3) * k << ' ' << (6 * i + 5) * k << endl;
	return 0;
}
