#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m;
const int maxn=150;
int val[maxn+5][maxn+5];
int dp[maxn+5][maxn+5];
int fa[maxn+5][maxn+5];

void print(int now,int place)
{
	if (now == 0) printf("%d ", place+1);
    else
    {
        print(now-1, fa[now][place]);
        if (now != n-1) printf("%d ", place+1);
        else printf("%d\n", place+1);
    }
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&val[i][j]);
	memset(dp,0xf1,sizeof(dp));
	
	for(int i=0;i<m;i++)
		dp[0][i]=val[0][i];
	//for(int i=1;i<n;i++)
	//	dp[i][i]=dp[i-1][i-1]+val[i][i];
	for(int i=1;i<n;i++)
		for(int j=0;j<m;j++)
			for(int k=i-1;k<j;k++)
			{
				if(dp[i-1][k]+val[i][j]>dp[i][j])
				{
					dp[i][j]=dp[i-1][k]+val[i][j];
					//ans[i-1]=k+1;
					fa[i][j]=k;
				}
				//dp[i][j]=max(dp[i][j],dp[i-1][k]+val[i][j]);
			}
	int sol=-1000000,place;
	for(int i=0;i<m;i++)
	{
		if(dp[n-1][i]>sol)
		{
			sol=dp[n-1][i];
			place=i;
		}
		//ans=max(ans,dp[n-1][i]);
	}
	printf("%d\n",sol);
	print(n-1,place);
	//printf("\n");	
}