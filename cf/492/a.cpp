#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> V;

int main()
{
	V.clear();
	for(int i = 0; i <= 100; i++)
		V.push_back(i * (i + 1) * (i + 2) / 6);
	int n;
	cin >> n;
	cout << upper_bound(V.begin(), V.end(), n) - V.begin() - 1 << endl;
	return 0;
}
