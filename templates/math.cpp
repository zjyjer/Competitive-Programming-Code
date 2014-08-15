#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod=1e9+7;
const int maxn=1e6+7;
int inv[maxn];
int prime[maxn];
int phi[maxn];
int mu[maxn];
int check[maxn];
int tot;
int fastpow(int a,int n) //a^n mod p
{
	long long ret=a;
	int tmp=a;
	while(n)
	{
		if(n&1)
			ret=ret*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ret;
}

long long xx,yy;
long long exgcd(long long a, long long b, long long &x, long long &y) //a*x+b*y=(a,b)
{
	if(b==0)
	{
		x=1, y=0;
		return a;
	}
	long long d=exgcd(b, a%b, y, x);
	y-=x * (a/b);
	return d;
}

void primetable(int n)
{
	memset(check, 1, sizeof(check));
	tot = 0;
	for(int i = 2;i <= n; i++) {
	//	printf("%d\n",i);
		if (check[i])
			prime[++tot] = i;
		for(int j = 1; ((j <= tot) && (i * prime[j] <= n)); j++)
		{
			check[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
}

int getphi(int n)
{
	int m=sqrt(n+0.5);
	int ans=n;
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

void phitable(int n)
{
	memset(check,false,sizeof(check));
	phi[1]=1;
	int tot=0;
	for(int i=2;i<=n;i++)
	{
		if(!check[i])
		{
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*phi[i]>n) break;
			check[i*phi[i]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
void miutable(int n)
{
	memset(check, 0, sizeof(check));
	mu[1] = 1;
	int tot = 0;
	for(int i = 2; i < n; i++) {
		if(!check[i]){
			prime[tot ++] = i;
			mu[i] = -1;
		}
		for(int j = 0; j < tot; j++) {
			if(i * prime[j] > maxn) break;
			check[i * prime[j]] = 1;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			} else {
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}
void invtable(int n)
{
	memset(inv,0,sizeof(inv));
	inv[1]=1;
	for(int i=2;i<n;i++)
	{
		int t=mod/i;
		int k=mod-t*i;
		inv[i]=(i*t%mod)*t%mod;
		inv[i]=(inv[i]*inv[k]%mod)*inv[k]%mod;
	}
}

vector <long long> line_mod_equation(long long a,long long b,long long n)
{
	// ax%n=b;
	long long x,y;
	long long d=exgcd(a,n,x,y);
	vector <long long> ans;
	ans.clear();
	if( b%d==0 ){
		x%=n;x+=n;x%=n;
		ans.push_back(x*(b/d)%(n/d));
		for(int i=1;i<=d;i++)
			ans.push_back((ans[0]+i*n/d)%n);
	}
	return ans;
}

int main()
{
	phitable(10000);
	long long ans = 0;
	for(int i = 9900; i <= 10000; i++)
		cout << getphi(i) << endl;
	return 0;
}