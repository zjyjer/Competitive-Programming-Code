#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	long long sum = a[0] + a[1] + a[2];
	cout << min(sum / 3 , a[0] + a[1]) << endl;
	return 0;
}
