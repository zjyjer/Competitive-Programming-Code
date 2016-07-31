#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset<pair<int, int> > S;

int main()
{
	int n, r, avg;
	cin >> n >> r >> avg;
	S.clear();
	long long sum = 0;
	long long s = (long long)n * avg;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a != r)
			S.insert(make_pair(b, a));
		sum += a;
	}
	if(sum >= s){
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	multiset<pair<int, int> >::iterator it;
	for(it = S.begin(); it != S.end(); it++)
	{
		int x = it->first;
		int y = it->second;
		if(sum + (long long)(r - y)  < s)
		{
			ans += (long long)(r - y) * x;
			sum += (long long)(r - y);
		}
		else{
			ans += (long long)(s - sum) * x; 
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
