#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <vector>
#include <iostream>

typedef std::complex <double> Complex;

const double PI = acos(-1);

void FFT(Complex* P, int n, int oper)
{
	for(int i = 1,j = 0; i < n-1; i++) {
		for (int s = n; j ^= s >>= 1, ~j & s;);
		if(i < j)
			std::swap(P[i],P[j]);
	}
	Complex unit_p0;
	for(int d = 0; (1<<d) < n; d++) {
		int m = 1 << d, m2 = m*2;
		double p0 = PI / m * oper;
		unit_p0 = Complex(cos(p0), sin(p0));
		for (int i = 0; i < n; i += m2) {
			Complex unit = 1;
			for (int j = 0; j < m; j++) {
				Complex &P1 = P[i + j + m], &P2 = P[i + j];
				Complex t = unit * P1;
				P1 = P2 - t;
				P2 = P2 + t;
				unit = unit * unit_p0;
			}
		}
	}
}

typedef std::vector <long long> Polynomial;

const int N = 1 << 18;
const int MOD = 119;

Complex A[N], B[N];
int q;

void add(int &x, int a)
{
	x += a;
	if (x >= MOD)
		x -= MOD;
}
long long a[100010];
long long sum[300010];
Polynomial operator * (const Polynomial &u, const Polynomial &v)
{
	int n = 1;
	while (n <= q + q )
		n <<= 1;
	for (int i = 0; i < n; i++)
		A[i] = i < q ? u[i] : 0;
	FFT(A, n, 1);
	for (int i = 0; i < n; i++)
		B[i] = i < q ? v[i] : 0;
	FFT(B, n, 1);
	for (int i = 0; i < n; i++)
		A[i] *= B[i];
	FFT(A, n, -1);
	Polynomial w(q + q);
	for (int i = 0; i < (int)w.size(); i++)
		w[i] = ((long long)(A[i].real() / n + 0.5));
	return w;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		std::cin >> n;
		for(int i = 0; i < n; i++)
		{
			scanf("%lld",a+i);
		}
		std::sort(a,a+n);
		q = (a[n-1] + 1) ;
		Polynomial v1(q);
		int len = 1;
		while (len <= q + q )
		len <<= 1;
		for(int i = 0; i < n; i++)
			v1[a[i]]++;
		Polynomial num(len);
		num = v1 * v1;
		/*
		for(int i = 0; i < len; i++)
			printf("%lld ",num[i]);
		printf("\n");
		*/
		for(int i = 0; i < n; i++)
			num[a[i]+a[i]]--;
		for(int i = 0; i < len; i++)
			num[i]/=2;
		/*
		for(int i = 0; i < len; i++)
			printf("%lld ",num[i]);
		printf("\n");
		*/
		sum[0] = 0;
		for(int i = 1; i < len; i++)
			{
				sum[i] = sum[i-1] + num[i];
				//printf("%lld ",sum[i]);
			}
		//printf("\n");
		long long cnt = 0;
		for(long long i = 0; i < n; i++)
		{
			cnt += sum[2*q-1] - sum[a[i]];
			cnt -= (long long)(n - 1 - i)*i;
			cnt -= (n-1);
			cnt -= (long long)(n - 1 - i)*(n - 2 - i)/2;
		}
		long long tot = n * (n - 1) * (n - 2) / 6;
		printf("%.7lf\n",(double)cnt/tot);
	}
}