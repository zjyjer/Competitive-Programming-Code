#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, g, phi;
int vis[1000010];
int powmod(int a, int m)
{
	int ret = 1;
	while(m)
	{
		if(m&1)
			ret = (long long)ret * a % n;
		a = (long long)a * a % n;
		m >>= 1;
	}
	return ret;
}
bool check(int x)
{
	if(powmod(x, phi) != 1)
		return false;
	int pow = x;
	int m = sqrt(phi+0.5);
	for(int i = 2; i <= m; i++)
	{
		if(phi % i == 0)
		{
			if(powmod(x, i) == 1 || powmod(x, phi/i) == 1)
				return false;
		}
	}
	return true;
}
int getphi(int n)
{
	int m =sqrt(n + 0.5);
	int ans = n;
	for(int i = 2; i <=m; i++)
	{
		if(n % i == 0)
			ans = ans / i * (i-1);
		while(n % i == 0)
			n /= i;
	}
	if(n!=1)
		ans = ans / n * (n-1);
	return ans;
}
int ans[1000010];
int gcd(int x, int y)
{
	if(x < y) swap(x, y);
	if(y == 0) return x;
	else return gcd(y, x%y);
}
int main()
{
	while(scanf("%d", &n)==1)
	{
		phi = getphi(n);
		for(int i = 2; i < n; i++)
		{
			if(check(i))
			{
				g = i;
				break;
			}
		}
		if(!g)
		{
			printf("-1\n");
			continue;
		}
		int step = 0;
		int root = 1;
		int phi2 = getphi(phi);
		for(int i = 0; i < phi; i++)
		{
			if(step  == phi2)
				break;
			if(gcd(i, phi)==1)
				ans[step++] = root;
			root = (long long)root * g % n;
		}
		sort(ans, ans+ step);
		for(int i = 0; i < step; i++)
		{
			if(i)
				printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
