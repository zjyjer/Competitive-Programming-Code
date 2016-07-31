#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1000000;
int tree[maxn*2];
int m = 1;

void buildtree(int o, int l, int r)
{
	int mid = (l + r) / 2;
	if(l == r)
		return;
	buildtree(o*2, l, mid);
	buildtree(o*2+1, mid + 1, r);
	tree[o] = tree[o * 2] + tree[o * 2 + 1];
}

int query(int o, int l, int r, int L, int R)
{
	if(l >= L && r <= R)
		return tree[o];
	else if(r < L || l > R)
		return 0;
	int mid = (l + r) / 2;
	return query(o * 2, l , mid, L, R) + query(o * 2 + 1, mid + 1, r, L, R);
}

void update(int a, int x)
{
	a--;
	a = m + a;
	while(a)
	{
		tree[a] += x;
		a /= 2;
	}
}
int main()
{
	int cas;
	scanf("%d", &cas);
	for(int i = 1; i <= cas; i++)
	{
		printf("Case %d:\n", i);
		int n;
		scanf("%d",&n);
		while(m  < n) m *= 2;
		for(int j = 0; j < n; j++)
			scanf("%d", &tree[m + j]);
		buildtree(1, 1, m);
		char oper[10];
		int l, r;
		while(1)
		{
			scanf("%s", oper);
			if(oper[0] == 'E')
				break;
			else if(oper[0] == 'Q')
			{
				scanf("%d %d" ,&l, &r);
				int ans = query(1, 1, m, l, r);
				printf("%d\n", ans);
			}
			else if(oper[0] == 'A')
			{
				scanf("%d %d", &l, &r);
				update(l, r);
			}
			else
			{
				scanf("%d %d", &l, &r);
				update(l, -r);
			}
		}
	}	
	return 0;
}

