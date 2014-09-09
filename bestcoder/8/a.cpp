#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
set <int> S;
int a[110];

int main()
{
	int n;
	while(cin >> n)
	{
		S.clear();
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			for(int j =i+1 ; j < n; j++)
				S.insert(a[i]+a[j]);
		long long sum = 0; 
		set<int>::iterator s;
		for(s = S.begin();s!=S.end();s++)
			sum += *s;
		cout << sum << endl;
	}
	return 0;
}
