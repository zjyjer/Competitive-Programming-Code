#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 400000;
int m = 1;
int tree[maxn << 1];

void buildtree(int o, int l, int r)
{
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	buildtree(o * 2, l, mid);
	buildtree(o * 2 + 1, mid+1, r);
	tree[o] = max(tree[o * 2], tree[o * 2 + 1]);
}

void update(int a, int x)
{
	a = a + m - 1;
	tree[a] = x;
	a /= 2;
	while(a)
	{
		tree[a] = max(tree[a * 2], tree[a * 2 + 1]);
		a /= 2;
	}
}

int query(int o, int l, int r, int L, int R)
{
	if(l >= L && r <= R)
		return tree[o];
	else if(l > R || r < L)
		return 0;
	int mid = (l + r) >> 1;
	return max(query(o * 2, l, mid, L, R), query(o * 2 + 1, mid + 1, r, L, R));
}
int main()
{
	int n, q;
	while(scanf("%d %d", &n, &q)==2)
	{
		m = 1;
		while(m * 2 < 2 * n) m *= 2;
		for(int i = 0; i < n; i++)
			scanf("%d", &tree[m + i]);
		buildtree(1, 1, m);
		char oper[5];
		int l, r;
		for(int i = 0; i < q; i++)
		{
			scanf("%s %d %d", oper, &l, &r);
			if(oper[0] == 'Q')
			{
				int ans = query(1, 1, m, l, r);
				printf("%d\n", ans);
			}
			else
			{
				update(l, r);
			}
		}
	}
	return 0;
}
