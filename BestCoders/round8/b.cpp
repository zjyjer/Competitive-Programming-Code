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

long long n,m,ans;
long long getphi(long long n)
{
	long long m=sqrt(n+0.5);
	long long ans=n;
	for(int i=2;i<=m;i++)
	{
		if(n%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		ans=ans/n*(n-1);
	return ans;
}
long long powmod(long long a, long long mm, long long mod)
{
	long long ret = 1;
	while(mm)
	{
		if(mm&1)
			ret = ret * a % mod;
		a = a * a % mod;
		mm >>= 1;
	}
	return ret;
}
int  inv[20];
void invtable(int n)
{
	memset(inv,0,sizeof(inv));
	inv[1]=1;
	for(int i=2;i<n;i++)
	{
		int t=m/i;
		int k=m-t*i;
		inv[i]=(i*t%m)*t%m;
		inv[i]=(inv[i]*inv[k]%m)*inv[k]%m;
	}
}

int main()
{
	while(cin >> n  >> m)
	{
		invtable(10);
		ans = 0;
		if(n&1)
			cout << ((powmod(4l, (n+1)/2,3*m) - 1 +3*m) % (3*m) /3 )% m << endl;
		else cout <<(((powmod(4l, n/2, 3*m ) -1) * 2 + 3*m) % (3*m) /3) % m << endl;
	}
	return 0;
}
