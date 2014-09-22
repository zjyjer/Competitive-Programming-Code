#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> S;
	S.clear();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		S.insert(x);
	}
	multiset<int>::iterator it;
	it = S.end();
	it--;
	cout << *it - *S.begin() << " ";
	if(*it!=*S.begin())
		cout << (long long)S.count(*it) * S.count(*S.begin()) << endl;
	else cout << (long long)n * (n-1)/2 << endl;
	return 0;
}
