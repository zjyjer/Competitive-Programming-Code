#include <cstdio>
#include <iostream>
using namespace std;
long long calcat(int n)
{
	long long ret=1;
	for(int i=1;i<=n;i++)
		ret=ret*(2*n-i+1)/(i);
	//printf("c(%d,%d)=%lld\n",2*n,n,ret);
	ret/=(n+1);
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
		cout << calcat(n) <<" " << n+1 << endl;
}