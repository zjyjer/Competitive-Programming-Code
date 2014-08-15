#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
long long mulmod(long long x, long long y, long long n)
{
	long long d = (long long)((long double)x*y/n);
	d = x * y - n * d;
	while(d < 0) d += n;
	while(d >= n) d -= n;
	return d;
}

long long powmod(long long a,long long n, long long mod)
{
	long long ret = 1;
	while(n)
	{
		if(n & 1)
			ret = mulmod(ret, tmp, mod);
		tmp = mulmod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}

long long strong_pseudo_primetest(long long n, int base) {
	long long n2 = n - 1, res;
	int s = 0;
	while (n2 % 2 == 0) n2>>=1, s++;
	res = powmod(base, n2, n);
	if((res == 1) || (res == n - 1)) return 1;
	s--;
	while(s >= 0) {
		res = mulmod(res, res, n);
		if(res == n - 1) return 1;
		s--;
	}
	return 0; //n is not a strong pseudo prime
}

int isprime(long long n) {
	if(n < 2) return 0;
	if(n < 4) return 1;
	if(strong_pseudo_primetest(n,2) == 0) return 0;
	if(strong_pseudo_primetest(n,3) == 0) return 0;
	if(n < 1373653LL) return 1;
	if(strong_pseudo_primetest(n,5) == 0) return 0;
	if(n < 2532600LL) return 1;
	if(strong_pseudo_primetest(n,7) == 0) return 0;
	if(n == 3215031751LL) return 0;
	if(n < 25000000000LL) return 1;
	if(strong_pseudo_primetest(n,11) == 0) return 0;
	if(n < 2152302898747LL) return 1;
	if(strong_pseudo_primetest(n,13) == 0) return 0;
	if(n < 3474749660383LL) return 1;
	if(strong_pseudo_primetest(n,17) == 0) return 0;
	if(n < 341550071728321LL) return 1;
	if(strong_pseudo_primetest(n,19) == 0) return 0;
	if(strong_pseudo_primetest(n,23) == 0) return 0;
	if(strong_pseudo_primetest(n,29) == 0) return 0;
	if(strong_pseudo_primetest(n,31) == 0) return 0;
	if(strong_pseudo_primetest(n,37) == 0) return 0;
	return 1;
}


int main()
{
	int n,a;
	while(cin >> n)
	{
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a);
			if(isprime(a))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}