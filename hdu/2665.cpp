#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 111111;
struct Node
{
	int l, r, sum;
}node[maxn * 20];
int tot;
int root[maxn];

void build(int l, int r, int &cur)
{
	cur = ++tot;
	node[cur].sum = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, node[cur].l);
	build(mid + 1, r, node[cur].r);
}

void update(int o, int p, int v, int l, int r, int &cur)
{
	cur = ++tot;
	node[cur].sum = node[o].sum + v;
	node[cur].l = node[o].l;
	node[cur].r = node[o].r;
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(node[o].l, p, v, l, mid, node[cur].l);
	else update(node[o].r, p, v, mid + 1, r, node[cur].r);
}	

int query(int o, int k, int l, int r, int cur)
{
	if(l == r)
		return l;
	int mid = (l + r) >> 1;
	int res = node[node[cur].l].sum - node[node[o].l].sum;
	if(res >= k)
		return query(node[o].l, k, l, mid, node[cur].l);
	else return query(node[o].r, k - res, mid + 1, r, node[cur].r);
}

int a[maxn], b[maxn];
int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			b[i] = a[i];
		}
		sort(a, a + n);
		int size = unique(a, a + n) - a;
		tot = 0;
		build(1, size, root[0]);
		for(int i = 0; i < n; i++)
		{
			b[i] = lower_bound(a, a + size, b[i]) - a + 1;
			update(root[i], b[i], 1, 1, size, root[i+1]);
		}
		while(m--)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			printf("%d\n", a[query(root[x-1], z, 1, size, root[y]) - 1]);
		}
	}
	return 0;
}
