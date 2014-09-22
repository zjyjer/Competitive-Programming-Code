#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
set<int> S;
bool  check(int s)
{
	char str[10];
	int cur =  0;
	while(s)
	{
		str[cur++] = s%10;
		s /= 10;
	}
	if(str[0] == str[5] && str[1] == str[4] && str[2] == str[3])
		return true;
	return false;
}

void init()
{
	S.clear();
	for(int i = 100; i <= 999; i++)
	{
		for(int j = i + 1; j <= 999; j++)
		{
			int pro = i * j;
			if(check(pro))
				S.insert(pro);
		}
	}
}

int solve(int n)
{
	set<int>::iterator s = S.lower_bound(n);
	return *(--s);
}

int main()
{
	init();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
