#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else return gcd(b,a%b);
}

int solve(int a,int b)
{
	if(a==b) return 1;
	if(a*b==0) return 0;
	if(a<b) swap(a,b);
	int t=gcd(a,b);
	a/=t,b/=t;//printf("%d %d\n",a,b);
	if(!(a%2 && b%2)) return -1;
	t=solve(a-b,2*b);
	return t==-1?-1:t+1;
}

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	printf("%d\n",solve(a,b));
}
