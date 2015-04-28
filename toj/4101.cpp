#include <iostream>

using namespace std;

int main()
{
	int cas;
	cin >> cas;
	while (cas--) {
		int n;
		cin >> n;
		long long i;
		for (i = 1; i * (i - 1) < n * 2; i++);
		cout << i - 1 << "\n";
	}
}
