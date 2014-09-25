#include <cstdio>
#include <cstring>

const int maxn = 111111;
long long sum[maxn << 2];
int tag[maxn << 2];
int m = 1;

void pushdown(int o, int l, int r)
{
	if(l != r && tag[o])
	{
		tag[o * 2] += tag[o];
		tag[o * 2 + 1] += tag[o];
		int mid = (l + r) >> 1;
		sum[o * 2] += (long long)tag[o] * (mid - l + 1);
		sum[o * 2 + 1] += (long long)tag[o] * (r - mid);
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

long long query(int o, int l, int r, int L, int R)
{
	if(L <= l && r <= R)
		return sum[o];
	pushdown(o, l, r);
	if(l > R || r < L)
		return 0;
	int mid = (l + r) >> 1;
	return query(o * 2, l, mid, L, R) + query(o * 2 + 1, mid + 1, r, L, R);
}

void update(int o, int l, int r, int L, int R, int c)
{
	if(L <= l && r <= R)
	{
		sum[o] += (long long)c * (r - l + 1);
		tag[o] += c;
		return;
	}
	if(R < l || L > r)
		return;
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	update(o * 2, l, mid, L, R, c);
	update(o * 2 + 1, mid + 1, r, L, R, c);
	sum[o] = sum[o * 2] + sum[o * 2 + 1];
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	while(m < n) m <<= 1;
	for(int i = m; i < m + n; i++)
		scanf("%lld", &sum[i]);
	char ch[5];
	build(1, 1, m);
	while(q--)
	{
		scanf("%s", ch);
		if(ch[0] == 'Q')
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(1, 1, m, a, b));
		}
		else
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			update(1, 1, m, a, b, c);
		}
	}
	return 0;
}
