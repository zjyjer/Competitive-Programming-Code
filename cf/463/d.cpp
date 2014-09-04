#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10][2000];
int loc[10][2000];
int deg[1010];
int dp[1010];
int head[1010], cur;
int vis[1010];
struct Edge
{
	int to, next;
}edge[1010000];

void addedge(int a, int b)
{
	edge[cur].to = b;
	edge[cur].next = head[a];
	head[a] = cur++;
}

void dfs(int n)
{
	vis[n] = 1;
	if(head[n]==-1)
		return;
	else
	{
		for(int j = head[n]; j!=-1; j=edge[j].next)
		{
			int t = edge[j].to;
			dp[t] = max(dp[t], dp[n]+1);
			deg[t]--;
			if(!deg[t] &&!vis[t])
			dfs(t);
		}
	}
}

int main()
{
	int n, k;
	scanf("%d %d",&n, &k);
	int h;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			loc[i][a[i][j]] = j;
		}
	memset(head, -1, sizeof(head));
	cur = 0;
	for(int i = 1; i<=n;i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(j == i) continue;
			bool ok = true;
			for(int p = 0; p < k; p++)
				if(loc[p][i] > loc[p][j])
				{
					ok = false;
					break;
				}
			if(ok)
			{
				addedge(i,j);
				deg[j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 0 && !vis[i])
		{
			dfs(i);	
		}
	}
	for(int i = 1; i <= n; i++)
		ans = max(dp[i], ans);
	printf("%d\n",ans+1);
	return 0;
}

