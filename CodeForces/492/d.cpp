#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
multiset<long long> S;
vector<long long> V;
map<long long, long long> M;

int main()
{
	int n;
	long long x, y;
	cin >> n >> x >> y;
	swap(x, y);
	long long gcd = __gcd(x, y);
	x /= gcd, y /= gcd;
	S.clear();
	M.clear();
	for(int i = 1; i < y; i++)
		S.insert(i * x);
	for(int i = 1; i < x; i++)
		S.insert(i * y);
	V.clear(); V.push_back(0);
	long long k = 1;
	multiset<long long>::iterator it;
	for(it = S.begin(); it != S.end(); it++)
	{
		M[k] = *it;
		V.push_back(k++);
	}
	while(n--)
	{
		long long a;
		cin >> a;
		a %= (x + y);
		if(a == 0 || a == x + y - 1)
			cout << "Both" << endl;
		else{
			int p = lower_bound(V.begin(), V.end(), a) - V.begin();
			if(M[p] % x == 0)
				cout << "Vanya" << endl;
			else cout << "Vova" << endl;
		}
	}
	return 0;
}
