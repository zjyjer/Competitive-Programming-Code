#include <cstdio>
#include <algorithm>
using namespace std;

int a[10000];
int n,k;
int main()
{
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		scanf("%d",a+i);
	sort(a,a+k);
	int ans=1,cur=1;
	for(int i=1;i<k;i++)
	{
		if(a[i]/1000!=a[i-1]/1000)
		{
			ans++;
			cur=1;
		}
		else if(cur==n)
		{
			ans++;
			cur=1;
		}
		else cur++;
	}
	printf("%d\n",ans+2);
	return 0;
}