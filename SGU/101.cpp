#include <cstdio>
#include <cstring>

int head[10];
struct Edge
{
	int to;
	int next;
	bool vis;
}edge[250];
int ans[150];
int p=0;
int cur;
int deg[10];
void init()
{
	memset(head,-1,sizeof(head));
	cur=0;
	memset(deg,0,sizeof(deg));
}

void addedge(int x,int y)
{
	deg[x]++;
	deg[y]++;
	edge[cur].to=y;
	edge[cur].next=head[x];
	head[x]=cur++;
	edge[cur].to=x;
	edge[cur].next=head[y];
	head[y]=cur++;
}

void dfs(int s)
{
	for(int i=head[s];i!=-1;i=edge[i].next)
	{
		//printf("%d\n",edge[i].to);
		if(!edge[i].vis)
		{
			edge[i].vis=edge[i^1].vis=1;
			dfs(edge[i].to);
			ans[p++]=i;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int x,y;
	init();
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		addedge(x,y);
	}
	int odd=0;
	for(int i=0;i<7;i++)
		if(deg[i]&1) odd++;
	if(odd>2)
	{
		puts("No solution");
		return 0;
	}
	int s;
	if(odd==0)
	{
		for(int i=0;i<7;i++)
			if(deg[i])
				s=i;
	}
	else
	{
		for(int i=0;i<7;i++)
			if(deg[i]&1)
				s=i;
	}
	dfs(s);
	//puts("***********************");
	//for(int i=0;i<2*n;i++)
	//	printf("%d %d\n",edge[i].vis,edge[i].to);
	for(int i=2*n-1;i>=0;i--)
		if(!edge[i].vis)
		{
			puts("No solution");
			return 0;
		}
	for(int i=0;i<p;i++)
		printf("%d %c\n",ans[i]/2+1,ans[i]%2?'+':'-');
}