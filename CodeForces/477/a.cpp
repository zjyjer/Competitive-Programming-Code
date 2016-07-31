#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

const int n = 10000;
const int mod = 1000000007;
int t;

int main()
{
	long long a, b;
	cin >> a >> b;
	long long k = a * (a + 1) / 2;
	k %= mod;
	k *= b;
	k %= mod;
	k += a;
	k %= mod;
	long long tmp = b * (b - 1)/2;
	tmp %=mod;
	k%=mod;
	k *= tmp;
	k %= mod;	
	cout << k << endl;
	return 0;
}
