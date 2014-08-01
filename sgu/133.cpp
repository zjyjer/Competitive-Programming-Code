#include <cstdio>
#include <algorithm>
using namespace std;

struct border
{
	int l,r;
}bord[20000];
bool cmp(border a,border b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	else return a.r < b.r;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&bord[i].l,&bord[i].r);
	}
	sort(bord,bord+n,cmp);
	int cur=bord[0].r;
	int ans=1;
	for(int i=1;i<n;i++)
	{
		if(cur < bord[i].r)
		{
			ans++;
			cur=bord[i].r;
		}
	}
	printf("%d\n",n-ans);
	return 0;
}