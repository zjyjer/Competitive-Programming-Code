#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	long long a[1100];
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		long long tmp= a[n-1];
		for(int i=n-2;i>=0;i--)
			{
				tmp = a[i]*(tmp+1)%9;
			}
		tmp=tmp%9;
		if(tmp==0 && n!=1)
			printf("9\n");
		else if(tmp==0)
			printf("0\n");
		else printf("%d\n",(int)tmp);
	}
	return 0;
}