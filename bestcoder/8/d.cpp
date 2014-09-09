#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

int n, phi, g, step;
int getphi(int n)
{
	int m = sqrt(n + 0.5);
	int ans = n;
	for(int i = 2; i <= m; i++)
	{
		if(n % i == 0)
			ans = ans / i * (i-1);
		while(n % i == 0)
			n /= i;
	}
	if(n!=1)
		ans = ans / n * (n - 1);
	return ans;
}
int powmod(long long a, int m)
{
	long long ret = 1;
	while(m)
	{
		if(m & 1)
			ret =  ret * a % n;
		a = a * a % n;
		m >>= 1;
	}
	return (int)ret;
}
const int maxn = 1000010;
int tot=0, prime[maxn], vis[maxn];
void init()
{
	for(int i = 2; i <= maxn; i++)
	{
		if(!vis[i])
			prime[++tot] = i;
		for(int j = 1; (j <= tot) && (i * prime[j] <= maxn); j++)
		{
			vis[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int f(int n)
{
	if(n % 2 == 0)
		return 0;
	for(int i = 2; i <= tot && prime[i] * prime[i] <= n; i++)
	{
		if(n % prime[i] == 0)
		{
			while(n % prime[i] == 0)
				n /= prime[i];
			if(n != 1)
				return 0;
			return prime[i];
		}
	}
	return n;
}

vector<int> V;

int check(int x)
{
	if(powmod(x, phi)!=1) return 0;
	for(int i = 0; i < V.size(); i++)
		if(powmod(x, V[i])==1)
			return 0;
	return 1;
}

int ans[maxn];

int gcd(int x, int y)
{
	if(x==0)
		return y;
	else return gcd(y%x, x);
}
int main()
{
	init();
	while(scanf("%d", &n)!=-1)
	{
		if(n==2)
		{
			puts("1");
			continue;
		}
		if(n==4)
		{
			puts("3");
			continue;
		}

		int flag = n%2==0? f(n/2):f(n);
		if(!flag)
		{
			puts("-1");
			continue;
		}

		phi = getphi(n);
		V.clear();
		int i;
		for(i = 2; i * i <= phi; i++)
		{
			if(phi % i == 0)
			{
				V.push_back(i);
				if(i * i != phi)
					V.push_back(phi / i);
			}
		}
		for(i = 2; i < 100; i++)
		{
			if(check(i))
				break;
		}		
		g = i;
		step = 0;
		int phi2 = getphi(phi);
		int pp=1;
		for(i = 1; i < phi; i++)
		{
			if(phi2 == step-1) break;
			pp = (long long)pp * g % n;
			if(gcd(i, phi)!=1) continue;
				ans[step++] = pp;
		}
		sort(ans, ans+step);
		for(i = 0; i < step; i++)
		{
			if(i) putchar(' ');
				printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
