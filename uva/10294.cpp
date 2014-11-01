#include <iostream>
#include <algorithm>
using namespace std;
long long fastpow(long long a, int n)
{
	long long ret = 1;
	while(n){
		if(n & 1)
			ret = ret * a;
		a = a * a;
	 	n >>= 1;
	}
	return ret;
}

int main()
{
	int n, t;
	while(cin >> n >> t){
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			ans += fastpow((long long)t, __gcd(n, i));
		ans /= n;
		long long tmp = fastpow((long long)t, (n+1)>>1);
		if(n & 1)
			cout << ans << ' ' << (ans + tmp) / 2 << endl;
		else cout << ans << ' ' << ((tmp * (1 + t) / 2) + ans) / 2 << endl;
	}
	return 0;
}
