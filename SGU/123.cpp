#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn=5;

struct Matrix
{
	long long num[maxn][maxn];
	int m,n;
};

Matrix mul(Matrix a,Matrix b)
{
	Matrix ans;
	memset(ans.num,0,sizeof(ans.num));
	ans.m=a.m;
	ans.n=b.n;
	for(int i=0;i<ans.m;i++)
		for(int j=0;j<ans.n;j++)
			for(int k=0;k<a.n;k++)
				{
					ans.num[i][j]+=a.num[i][k]*b.num[k][j];
					//m3.a[i][j]%=mod;
				}
	return ans;
}

Matrix init()
{
	Matrix ans;
	for(int i=0;i<maxn;i++)
			ans.num[i][i]=1;
}
Matrix fastpow(Matrix a,int n)
{
	Matrix ret=init();
	ret.m=a.m;
	ret.n=a.n;
	Matrix tmp=a;
	while(n)
	{
		if(n&1)
			ret=mul(ret,tmp);
		tmp=mul(tmp,tmp);
		n>>=1;
	}
	return ret;
}
Matrix ans,a;
void ini()
{
	a.m=a.n=3;
	a.num[0][1]=1;
	a.num[1][0]=1;
	a.num[1][1]=1;
	a.num[2][1]=1;
	a.num[2][2]=1;
	ans.m=3;ans.n=1;
	ans.num[0][0]=1;
	ans.num[1][0]=1;
	ans.num[2][0]=1;
}

void output(Matrix a)
{
	int m=a.m;
	int n=a.n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout << a.num[i][j]<<" ";
		cout << endl;
	}
}
void solve(int n)
{	
	a=fastpow(a,n);
	ans=mul(a,ans);
	cout << ans.num[0][0] <<" " << ans.num[1][0] <<" "<<ans.num[2][0] << endl;
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		ini();
		//solve(n);
		//output(a);
		//output(ans);
		for(int i=0;i<n-1;i++)
		ans=mul(a,ans);
		printf("%lld\n",ans.num[2][0]);
		//printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
		//output(ans);
		//printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	}
}