#include <cstdio>

int solve(int n)
{
	int ans=0;
	while(n)
	{
		ans+=n/5;
		n/=5;
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int low=0,high=0x3f3f3f3f;
	if(n==0)
	{
		printf("1\n");
	}
	while(low<high)
	{
		//printf("%d %d\n",low,high);
		int mid=(low+high)>>1;
		if(solve(mid)<n)
			low=mid+1;
		else high=mid;
	}
	if(solve(low)==n)
	printf("%d\n",low);
	else printf("No solution\n");
}