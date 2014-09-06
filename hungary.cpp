#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

bool g[510][510];
int link[510];
bool b[510];
int ans,n,m;

void init()
{
	memset(g,0,sizeof(g));
	memset(link,0,sizeof(link));
	scanf("%d %d",&n,&m);
	int x,y;
	ans=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		g[x][y]=1;
	}
}

bool find(int a)
{
	for(int i=1;i<=n;i++)
	{
		if(g[a][i]==1 && !b[i])
		{
			b[i]=1;
			if(link[i]==0 || find(link[i]))
			{
				link[i]=a;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		if(find(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
