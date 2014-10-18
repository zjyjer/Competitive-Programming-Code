#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b==0)
	{
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y -= x*(a/b);
	return d;
}
inline ll mod(ll a, ll b){return a%b+(a%b>0?0:b);}
ll excrt(ll a[], ll m[], int n,int lim)
{
	//cout << n << endl;
	if(n==1 && a[0]==0)
		return lim / m[0] ;
		//return m[0];
	ll ans = a[0], lcm = m[0];
	bool legal = true;
	for(int i = 1;  i < n; i++)
	{
		ll x, y, gcd;
		gcd = exgcd(lcm, m[i], x, y);
		if((a[i] - ans)%gcd)
		{
			legal = false;
			break;
		}
		ll tmp = lcm*mod((a[i] - ans)/gcd*x, m[i]/gcd);
		lcm = lcm/gcd*m[i];
		ans = mod(ans + tmp, lcm);
	}
	//cout << lcm << endl;
	//return legal?ans:-1;
	if(!legal) return 0;
	if(lim < ans) return 0;
	else return (lim - ans)/lcm + 1;
	/*
	int step=0;
	while(lim >= ans)
	{
		step++;
		ans+=lcm;
	}
	return step;
	*/
}
ll a[100],m[100];

int main()
{
	freopen("data.in", "r", stdin);
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++)
	{
		int n, lim;
		cin >> lim >> n;
		for(int i = 0; i < n; i++)
			cin >> m[i];
		for(int i = 0; i < n; i++)
			cin >> a[i];

		cout << excrt(a, m, n, lim) << endl;
	}
	return 0;
}
