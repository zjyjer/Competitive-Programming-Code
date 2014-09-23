#include <cstdio>
#include <cstring>

int m = 1;
const int maxn = 2000010;
int ord[maxn], num[maxn], ans[maxn];
int tree[maxn << 2];

void buildtree(int n)
{
	for(int i = m; i < m + n; i++)
		tree[i] = 1;
	for(int i =  m - 1; i >= 1; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int query(int o, int l, int r, int num)
{
	if(l == r)
		return o;
	if(tree[o] > num)
	{
		int mid = (l + r) >> 1;
		if(tree[o * 2] > num)
			return query(o * 2, l, mid, num);
		else return query(o * 2 + 1, mid + 1, r, num - tree[o * 2]);
	}
}

void update(int a, int x)
{
	ans[a - m] = x;
	tree[a] = 0;
	a /= 2;
	while(a)
	{
		tree[a]--;
		a /= 2;
	}
}
int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		while(m < n) m *= 2;
		for(int i = 0; i < n ; i++)
			scanf("%d %d", &ord[i], &num[i]);
		buildtree(n);
		for(int i = n - 1; i >= 0; i--)
		{
			int pos = query(1, 1, m, ord[i]);
			update(pos, num[i]);
		}
		printf("%d", ans[0]);
		for(int i = 1; i < n; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
