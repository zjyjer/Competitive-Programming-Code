#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

long long gcd(long long a,long long b)
{
	if(a%b==0)
		return b;
	else return gcd(b,a%b);
}

long long fastpow(long long a,long long n)
{
	long long ret=1;
	long long tmp=a;
	while(n)
	{
		if(n&1)
			ret=ret*tmp;
		tmp=tmp*tmp;
		n>>=1;
	}
	return ret;
}

int main()
{
	long long c=2,s;
	while(cin>> s && c+s)
	{
		long long ans=0;
		for(int i=1;i<=s;i++)
			ans+=fastpow(c,gcd(s,i));
		if(s&1)
			ans+=s*fastpow(c,s/2+1);
		else ans+=(c+1)*s/2*fastpow(c,s/2);
		cout << ans/s/2 << endl;
	}
	return 0;
}
