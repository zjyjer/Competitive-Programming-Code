#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int m = 1;
int tree[maxn << 1];
int a[maxn];
int query(int o, int l, int r, int L, int R)
{
	if(l >= L && r <= R)
		return tree[o];
	if(l > R || r < L)
		return 0;
	int mid = (l + r) >> 1;
	return query(o*2, l, mid, L, R) + query(o*2 + 1, mid + 1, r, L, R);
}

void update(int a, int x)
{
	a += m - 1;
	tree[a] = x;
	a >>= 1;
	while(a)
	{
		tree[a] = tree[a * 2] + tree[a * 2 + 1];
		a /= 2;
	}
}

int main()
{
	int n;
	while(scanf("%d", &n)==1)
	{
		while(m < n) m *= 2;
		int sum = 0;
		memset(tree, 0, sizeof(tree));
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			a[i]++;
			sum += i - query(1, 1, m, 1, a[i]);
			update(a[i], 1);
		}
		int ans = sum;
		for(int i = 0; i < n; i++)
		{
			ans = min(ans, sum+ n + 1 - 2 * a[i]);
			sum = sum + 1 + n - 2 * a[i];
		}		
		printf("%d\n", ans);
	}
	return 0;
}


