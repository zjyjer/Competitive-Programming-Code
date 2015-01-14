#pragma GCC OPTIMIZE O2
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <complex>

typedef std::complex <double> Complex;

const double PI = acos(-1.0);
 
void FFT(Complex* P, int n, int oper)
{
	for(int i = 1, j = 0; i < n - 1; i++){
		for (int s = n; j ^= s >>= 1, ~j&s;);
		if(i < j)
			std::swap(P[i], P[j]);
	}
	Complex unit_p0;
	for(int d = 0; (1 << d ) < n; d++) {
		int m = 1 << d, m2 = m << 1;
		double p0 = PI / m * oper;
		unit_p0 = Complex(cos(p0),sin(p0));
		for (int i = 0; i < n; i += m2) {
			Complex unit = 1;
			for(int j = 0; j < m; j++) {
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

Complex A[N], B[N];
int q;
const int maxn = 20000;
int a[(maxn << 1) + 100];
int ans[(maxn << 1) + 100];
Polynomial operator * (const Polynomial &u, const Polynomial &v)
{
	int n = 1;
	while ( n <= q + q - 2)
		n <<= 1;
	for (int i = 0; i < n; i++)
		A[i] = i < q ? u[i] : 0;
	FFT(A, n, 1);
	for(int i = 0; i < n; i++)
		B[i] = i < q ? v[i] : 0;
	FFT(B, n, 1);
	for(int i = 0; i < n; i++)
		A[i] *= B[i];
	FFT(A, n, -1);
	Polynomial w(2*n);
	for (int i = 0; i < (int)w.size(); i++)
		w[i] = (long long)(A[i].real() /n + 0.5);
	return w;
}

int main()
{
	int n,tmp;
	//freopen("data.in","r",stdin);
	//freopen("data2.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&tmp);
		a[i]= tmp + maxn;
	}
	std::sort(a,a+n);
	q = a[n-1] + 1;
	int min = a[0] - maxn;
	int max = a[n-1]+1 - maxn;
	int len =1;
	while (len <= 2*q)
		len <<= 1;
	Polynomial v1(len);
	Polynomial v2(len*2);
	Polynomial v3(len*3);
	for(int i = 0; i < n; i++)
	{
		v1[a[i]]++;
		v2[a[i]*2]++;
		v3[a[i]*3]++;
	}
	Polynomial v4(len * 4);
	Polynomial v5(len * 4);
	v4 = v1 * v1;q *= 2;
	//printf("%d %d %d\n",v2.size(),v4.size(),v5.size());
	
	for(int i = 0; i <  v2.size(); i++)
		v5[i] = -3*v2[i] + v4[i];
	//v4 = v4 * v1;
	
	v5 = v5 * v1;
	//printf("%d %d %d\n",v2.size(),v4.size(),v5.size());
	//printf("%d %d\n",min,max);
	for(int i = min;i <= 3*max; i++)
		if((v5[i+3*maxn]+2*v3[i+3*maxn])/6)
		printf("%d : %d\n",i,(v5[i+3*maxn]+2*v3[i+3*maxn])/6);
	printf("\n");
}