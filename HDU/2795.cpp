#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h, w, n;
int m = 1;
const int maxn = 400000;
int tree[maxn<<1];

void buildtree()
{
	for(int i = 1; i < n + m ; i++)
		tree[i] = w;
}

void update(int o, int x)
{
	tree[o] -= x;
	o /= 2;
	while(o)
	{
		tree[o] = max(tree[o * 2] , tree[o * 2 + 1]);
		o >>= 1;
	}
}

int query(int o, int l, int r, int num)
{
	if(tree[o] < num)
		return -1;
	if(l == r)
	{
		update(o, num);
		return o - m + 1;
	}
	int mid = (l + r) >> 1;
	if(tree[o*2] >= num)
		return query(o * 2, l, mid, num);
	else if(tree[o*2 + 1] >= num)return query(o * 2 + 1, mid + 1, r, num);
}

int main()
{
	while(scanf("%d %d %d", &h, &w, &n)==3)
	{
		int tmp;
		while(m < n) m <<= 1;
		buildtree();
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			int ans = query(1, 1, m, tmp);
			if(ans > h) ans = -1;
			printf("%d\n", ans);
		}
	}
	return 0;
}
