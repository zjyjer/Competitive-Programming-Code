#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 111111;
int sum[maxn << 2];
int tag[maxn << 2];
int m = 1;

void pushdown(int o, int l, int r)
{
	if(tag[o])
	{
		tag[o * 2] = tag[o * 2 + 1] = tag[o];
		int mid = (l + r) >> 1;
		sum[o * 2] = tag[o] * (mid - l + 1);
		sum[o * 2 + 1] = tag[o] * (r - mid);
		tag[o] = 0;
	}
}

void build(int o, int l, int r)
{
	tag[o] = 0;
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	build(o * 2, l, mid);
	build(o * 2 + 1, mid + 1, r);
	sum[o] = sum[o * 2] + sum[o * 2 + 1];
}

void update(int o, int l, int r, int L, int R, int c)
{
	if(L <= l && r <= R)
	{
		tag[o] = c;
		sum[o] = c * (r - l + 1);
		return;
	}
	if(l != r)
		pushdown(o, l, r);
	int mid = (l + r) >> 1;
	if(l > R || r < L) return;
	update(o * 2, l, mid, L, R, c);
	update(o * 2 + 1, mid + 1, r, L, R, c);
	sum[o] = sum[o * 2] + sum[o * 2 + 1];
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++)
	{
		int n, q;
		m = 1;
		scanf("%d %d", &n, &q);
		while(m < n) m *= 2;
		memset(sum, 0, sizeof(int) * 2 * m);
		memset(tag, 0, sizeof(int) * 2 * m);
		for(int i = m; i < m + n; i++)
			sum[i] = 1;
		build(1, 1, m);
		while(q--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			update(1, 1, m, a, b, c);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas, sum[1]);
	}
	return 0;
}
