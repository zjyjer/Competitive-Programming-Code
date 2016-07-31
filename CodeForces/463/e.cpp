#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 100010;
const int maxm = 2000010;
const int maxx = 2010;
vector<int> G[maxn],V[maxn];
int val[maxn];
int dep[maxn];
int pri[maxx], pnum,ans[maxn];
bool vis[maxx];
int f[maxm];
int head[maxn], cur;
struct Edge
{
	int to, next;
}edge[maxn << 1];

void addedge(int a, int b)
{
	edge[cur].to = b;
	edge[cur].next = head[a];
	head[a] = cur++;
}

void primetable()
{
	pnum = 0;	
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i < maxx; i++)
	{
		if(!vis[i])
		{
			pri[pnum++] = i;
		}
		for(int j = 0; ((j < pnum) && (i * pri[j] < maxx)); j++)
		{
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

void update(int n)
{
	G[n].clear();
	int value = val[n];
	for(int i = 0; i < pnum && pri[i] * pri[i] <= value; i++)
	{
		if(value % pri[i] == 0)
		{
			G[n].push_back(pri[i]);
			while(value % pri[i] == 0)
				value /= pri[i];
		}
	}
	if(value!=1)
		G[n].push_back(value);
}

void dfs(int u, int fa, int d)
{
	dep[u] = d;
	for(int i = 0; i < G[u].size(); i++)
	{
		int p = G[u][i];
		if(f[p] == -1)
			continue;
		if(ans[u] == -1)
			ans[u] = f[p];
		else if(dep[ans[u]] < dep[f[p]])
			ans[u] = f[p];
	}
	V[u].clear();
	for(int i = 0; i < G[u].size(); i++)
	{
		int p = G[u][i];
		V[u].push_back(f[p]);
		f[p] = u;
	}
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		if(edge[i].to != fa)
			dfs(edge[i].to, u, d+1);
	}
	for(int i = 0; i < G[u].size(); i++)
	{
		int p = G[u][i];
		f[p] = V[u][i];
	}
}
void init()
{
	memset(f, -1, sizeof(f));
	memset(ans, -1 , sizeof(ans));
	dfs(1, -1, 0);
}
int main()
{
	primetable();
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		update(i);
	}
	int x, y;
	cur = 0;
	memset(head, -1 , sizeof(head));
	for(int i = 1; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	int op;
	init();
	for(int i = 0; i < q; i++)
	{
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d", &x);
			printf("%d\n", ans[x]);
		}
		else
		{
			scanf("%d %d", &x, &y);
			val[x] = y;
			update(x);
			init();
		}
	}
	return 0;
}
