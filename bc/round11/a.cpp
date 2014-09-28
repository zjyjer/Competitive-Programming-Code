#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{

	int a, b, c ,d;
	while(cin >> a >> b >> c >> d)
	{
		if ( c + c ==  a && d + d == b)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
