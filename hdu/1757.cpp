#include <cstdio>
#include <cstring>
#include <iostream>
struct Matrix
{
	int m,n;
	long long a[11][11];
};
long long k,mod;
Matrix E(int n)
{
	Matrix e;
	e.n = e.m = n;
	memset(e.a, 0, sizeof(e.a));
	for(int i = 0; i < n; i++)
		e.a[i][i] = 1;
	return e;
}

void output(Matrix a)
{
	for(int i = 0; i < a.m; i++)
	{
		for(int j = 0; j < a.n; j++)
			printf("%2I64d ",a.a[i][j]);
		printf("\n");
	}
}

Matrix operator * (const Matrix &a, const Matrix &b)
{
	Matrix mul;
	mul.m = a.m, mul.n = b.n;
	memset(mul.a, 0, sizeof(mul.a));
	for(int i = 0; i < mul.m; i++)
		for(int j = 0; j < mul.n; j++)
			for(int k = 0; k < a.n; k++)
				{
					mul.a[i][j] += (a.a[i][k] * b.a[k][j]) % mod;
					mul.a[i][j] %= mod;
				}
	return mul;
}

Matrix fastpow(const Matrix &a, int n)
{
	Matrix ret = E(a.n);
	Matrix tmp = a;
	while(n)
	{
		if(n & 1)
			ret = ret * tmp;
		tmp = tmp * tmp;
		n >>= 1;
	}
	return ret;
}

Matrix m,ans;

void init()
{
	m.m = 10, m.n = 10;
	ans.m = 10; ans.n = 1;
	memset(m.a,0,sizeof(m.a));
	for(int i = 1; i < 10; i++)
		m.a[i][i-1] = (long long)1;
	for(int i = 0; i < 10; i++)
		ans.a[i][0] = (long long)(9 - i);
	//output(ans);
	//output(m);
}

int main()
{	
	//freopen("data.in","r",stdin);
	while(std::cin >> k >> mod)
	{
		init();
		//output(ans);
		for(int i = 0; i < 10; i++)
			std::cin >> m.a[0][i];
			//scanf("%I64d", &m.a[0][i]);
		if(k <= 9)
		{
			std::cout << k % mod << std::endl;
			continue;
		}
		//output(m);
		//output(m * m);
		m = fastpow(m,k - 9);
		//output(m);
		ans = m * ans;
		//output(ans);
		std::cout << ans.a[0][0] % mod << std::endl;
		//printf("%I64d\n",ans.a[0][0]%mod);	
	}
	return 0;
}