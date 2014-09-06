#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=100010;
const int DEEP=20;

int seq[DEEP][N]; //归并树
int a[N], n, m;
struct node
{
	int l, r, mid;
} tree[N*4]; //线段树

//线段树+归并树一起建了，实际上二者的过程一样。。
void build(int l, int r, int p, int deep)
{
	tree[p].l = l;
	tree[p].r = r;
	tree[p].mid = (l+r)>>1;
	if(l==r)
	{
		seq[deep][l] = a[l];
		return;
	}
	build(l, tree[p].mid, p*2, deep+1);
	build(tree[p].mid+1, r, p*2+1, deep+1);

	//归并过程
	int i, j, k;
	for(i=l, j=tree[p].mid+1, k=l; i<=tree[p].mid && j<=r; )
	{
		if(seq[deep+1][i]>seq[deep+1][j])
			seq[deep][k++] = seq[deep+1][j++];
		else
			seq[deep][k++] = seq[deep+1][i++];
	}
	while(i<=tree[p].mid)
		seq[deep][k++] = seq[deep+1][i++];
	while(j<=r)
		seq[deep][k++] = seq[deep+1][j++];
}

//通过二分枚举，返回key在本区间大于多少个数
//注意：任何一个通过线段树最终到达的区间一定是已经排好序了的，所以可以通过二分求
int counthelp(int l, int r, int p, int key, int deep)
{
	int mid;
	while(l<=r)
	{
		mid = (l+r)>>1;
		if(seq[deep][mid]<key)
			l = mid+1;
		else
			r = mid-1;
	}
	return r-tree[p].l+1;
}
//返回key在[l, r]总区间内大于几个数
int count(int l, int r, int p, int key, int deep)
{
	if(tree[p].l==l && tree[p].r==r)
	{
		return counthelp(l, r, p, key, deep);
	}
	if(r<=tree[p].mid)
		return count(l, r, p*2, key, deep+1);
	else if(l>tree[p].mid)
		return count(l, r, p*2+1, key, deep+1);
	else
	{
		return count(l, tree[p].mid, p*2, key, deep+1)+count(tree[p].mid+1, r, p*2+1, key, deep+1);
	}
}

//返回在通过二分枚举后得到的结果。。。
int query(int ll, int rr, int cnt)
{
	int mid, tmp;
	int l = 1;
	int r = n;
	while(l<=r)
	{
		mid = (l+r)>>1;
		tmp = count(ll, rr, 1, seq[1][mid], 1); 
		if(tmp>=cnt)
			r = mid-1;
		else
			l = mid+1;
	}
	return seq[1][l-1];
}

int main()
{
	int i, x, y, cnt;
	int t;
	cin >> t;
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++)
			scanf("%d", &a[i]);
		build(1, n, 1, 1);
		while(m--)
		{
			scanf("%d%d%d", &x, &y, &cnt);
			printf("%d\n", query(x, y, cnt));
		}
	}
	return 0;
}
