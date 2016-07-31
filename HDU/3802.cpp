#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
long long powmod(long long a, int n, int p)
{
	long long ret = 1;
	while(n)
	{
		if(n&1)
			ret = ret * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ret;
}
struct Matrix
{
	int m, n;
	long long a[5][5];
};
Matrix m1, m2;
void init()
{
	m1.m = 2;
	m1.n = 2;
	m1.a[0][0] = 1;
	m1.a[0][1] = 1;
	m1.a[1][0] = 1;
	m1.a[1][1] = 0;
	m2.m = 2;
	m2.n = 1;
	m2.a[0][0] = 1;
	m2.a[1][0] = 0;
}
void init2(int a, int b, int p)
{
	m1.m = 2;
	m1.n = 2;
	m1.a[0][0] = (long long)(2*a + 2*b)%p;
	m1.a[0][1] = (long long)((a - b)*(a - b)*-1+p) %p;
	m1.a[1][0] = 1;
	m1.a[1][1] = 0;
	m2.m = 2;
	m2.n = 1;
	m2.a[0][0] = (long long) (a+b)*2 % p;
	m2.a[1][0] = 2;
}
Matrix mul (Matrix m1, Matrix m2, int p)
{
	Matrix m3;
	memset(m3.a , 0 , sizeof(m3.a));
	m3.m = m1.m;
	m3.n = m2.n;
	for(int i = 0; i < m1.m; i++)
		for(int j = 0; j < m3.n; j++)
			for(int k = 0; k < m3.m; k++)
				{
					m3.a[i][j] += m1.a[i][k] * m2.a[k][j];
					m3.a[i][j] = (m3.a[i][j] + p)%p;
				}
	return m3;
}
Matrix E(int n)
{
	Matrix a;
	a.m = a.n = n;
	memset(a.a, 0, sizeof(a.a));
	for(int i = 0; i < n; i++)
		a.a[i][i] = 1;
	return a;
}
Matrix powmod(Matrix a, int n, int p)
{
	Matrix ret = E(a.m);
	ret.m = a.m;
	ret.n = a.n;
	while(n)
	{
		if(n&1)
			ret = mul(ret, a, p);
		a = mul(a, a, p);
		n >>= 1;
	}
	return ret;
}
int main()
{
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	int a,b,n,p;
	while(t--)
	{
		scanf("%d %d %d %d",&a, &b, &n, &p);
		long long ans = powmod((long long)a, (p-1)/2, p) + 1;
		ans *= (powmod((long long)b, (p-1)/2, p) + 1);
		init();	
		m1 = powmod(m1, n, p-1);
		m2 = mul(m1, m2, p-1);
		long long fib = m2.a[0][0] % (p-1);
		init2(a, b, p);	
		m1 = powmod(m1,fib-1,p);
		m2 = mul(m1, m2, p);
		cout << (long long)ans * m2.a[0][0] %p << endl;
	}
}