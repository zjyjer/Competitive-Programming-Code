#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long a,b,c;

long long gcd(long long a,long long b)
{
		if(b%a==0)
				return a;
		else return gcd(b%a,a);
}
int main()
{
		int n;
		while(scanf("%d",&n)==1)
		{
				b=1;c=1;
				for(int i=2;i<=n;i++)
				{
						b=b*i+c;
						c=i*c;
						long long g=gcd(b,c);
						b/=g;
						c/=g;
				}
		long long g=gcd(n,c);
		b*=n/g;
		c/=g;
		a=b/c;
		b=b%c;
		long long aa=a,bb=b,cc=c;
		int len1=0,len2=0;
		while(aa)
		{
			aa/=10;
			len1++;
		}	
		while(cc)
		{
				cc/=10;
				len2++;
		}
		if(b==0)
				cout << a << endl;
		else
		{
				for(int i=0;i<=len1;i++)
						printf(" ");
				printf("%lld\n",b);
				printf("%lld ",a);
				for(int i=0;i<len2;i++)
						printf("-");
				printf("\n");
				for(int i=0;i<=len1;i++)
						printf(" ");
				printf("%lld\n",c);
		}
	//	cout << a << b << c << endl;
		}
		return 0;
}
