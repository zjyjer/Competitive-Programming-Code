#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
set<int> S;
int a[110];
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
			cin >> a[i];
		S.clear();
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				S.insert(a[i]+a[j]);
		long long sum = 0;
		set<int>::iterator it;
		for(it = S.begin(); it != S.end(); it++)
			sum += *it;
		cout << sum << endl;
	}
	return 0;
}
