/*
	poj 3237
*/
#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;
class Node
{
public:
	int left,right,ma,mi,lazy;
	Node(){}
};
class Edge
{
public:
	int to,next,val;
	Edge(int a=0,int b=0,int c=0)
	{
		to=a,next=b,val=c;
	}
};
const int MAXN=10111;
Node tree[MAXN*4];
Edge edge[MAXN*2];
int cases,n,edge_num,posi;
int head[MAXN];
int size[MAXN],son[MAXN],top[MAXN],father[MAXN],depth[MAXN],pos[MAXN],rpos[MAXN];
int e[MAXN][3];
void init()
{
	memset(head,-1,sizeof(head));
	memset(son,-1,sizeof(son));
	edge_num=0,posi=0;
}
void add_edge(int a,int b,int c)
{
	edge[edge_num]=Edge(b,head[a],c);
	head[a]=edge_num++;
}
void dfs1(int p,int f,int d)
{
	father[p]=f;
	size[p]=1;
	depth[p]=d;
	for(int i=head[p];i!=-1;i=edge[i].next)
	{
		int u=edge[i].to;
		if(u==f)continue;
		dfs1(u,p,d+1);
		size[p]+=size[u];
		if(son[p]==-1||size[u]>size[son[p]])
			son[p]=u;
	}
}
void dfs2(int p,int itop)
{
	top[p]=itop;
	pos[p]=posi;
	rpos[posi++]=p;
	if(son[p]==-1)return;
	dfs2(son[p],itop);
	for(int i=head[p];i!=-1;i=edge[i].next)
	{
		int u=edge[i].to;
		if(u==son[p]||u==father[p])continue;
		dfs2(u,u);
	}
}
void build_tree(int p,int left,int right)
{
	tree[p].left=left,tree[p].right=right;
	tree[p].mi=tree[p].ma=tree[p].lazy=0;
	if(left==right)return;
	int mid=(left+right)/2;
	build_tree(p*2,left,mid);
	build_tree(p*2+1,mid+1,right);
}
void pushdown(int p)
{
	if(tree[p].left==tree[p].right)return;
	if(tree[p].lazy)
	{
		tree[p*2].ma=-tree[p*2].ma;
		tree[p*2].mi=-tree[p*2].mi;
		swap(tree[p*2].ma,tree[p*2].mi);
		tree[p*2+1].ma=-tree[p*2+1].ma;
		tree[p*2+1].mi=-tree[p*2+1].mi;
		swap(tree[p*2+1].ma,tree[p*2+1].mi);
		tree[p*2].lazy^=1;
		tree[p*2+1].lazy^=1;
		tree[p].lazy=0;
	}
}
void pushup(int p)
{
	tree[p].ma=max(tree[p*2].ma,tree[p*2+1].ma);
	tree[p].mi=min(tree[p*2].mi,tree[p*2+1].mi);
}
void insert(int p,int q,int v)
{
	if(tree[p].left==tree[p].right)
	{
		tree[p].ma=tree[p].mi=v;
		return;
	}
	pushdown(p);
	int mid=(tree[p].left+tree[p].right)/2;
	if(q<=mid)insert(p*2,q,v);
	else if(q>mid)insert(p*2+1,q,v);
	pushup(p);
}
void tree_negate(int p,int left,int right)
{
	if(tree[p].left==left&&tree[p].right==right)
	{
		tree[p].ma=-tree[p].ma;
		tree[p].mi=-tree[p].mi;
		swap(tree[p].ma,tree[p].mi);
		tree[p].lazy^=1;
		return;
	}
	pushdown(p);
	int mid=(tree[p].left+tree[p].right)/2;
	if(right<=mid)tree_negate(p*2,left,right);
	else if(left>mid)tree_negate(p*2+1,left,right);
	else tree_negate(p*2,left,mid),tree_negate(p*2+1,mid+1,right);
	pushup(p);
}
int query(int p,int left,int right)
{
	if(tree[p].left==left&&tree[p].right==right)
		return tree[p].ma;
	pushdown(p);
	int mid=(tree[p].left+tree[p].right)/2;
	if(right<=mid)return query(p*2,left,right);
	else if(left>mid)return query(p*2+1,left,right);
	else return max(query(p*2,left,mid),query(p*2+1,mid+1,right));
}
int findmax(int a,int b)
{
	int f1=top[a],f2=top[b];
	int ans=-100000000;
	while(f1!=f2)
	{
		if(depth[f1]<depth[f2])
			swap(f1,f2),swap(a,b);
		ans=max(ans,query(1,pos[f1],pos[a]));
		a=father[f1],f1=top[a];
	}
	if(a==b)return ans;
	if(depth[a]>depth[b])swap(a,b);
	return max(ans,query(1,pos[son[a]],pos[b]));
}
void Negate(int a,int b)
{
	int f1=top[a],f2=top[b];
	while(f1!=f2)
	{
		if(depth[f1]<depth[f2])
			swap(f1,f2),swap(a,b);
		tree_negate(1,pos[f1],pos[a]);
		a=father[f1],f1=top[a];
	}
	if(a==b)return;
	if(depth[a]>depth[b])swap(a,b);
	tree_negate(1,pos[son[a]],pos[b]);
}
int main()
{
	scanf("%d",&cases);
	while(cases--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
			add_edge(e[i][0],e[i][1],e[i][2]);
			add_edge(e[i][1],e[i][0],e[i][2]);
		}
		dfs1(1,0,0);//结点号,父节点,深度
		dfs2(1,1);
		build_tree(1,0,posi-1);
		for(int i=1;i<n;i++)
		{
			if(depth[e[i][0]]>depth[e[i][1]])
				swap(e[i][0],e[i][1]);
			insert(1,pos[e[i][1]],e[i][2]);
		}
		char oper[12];
		int a,b;
		while(scanf("%s",oper))
		{
			if(oper[0]=='D')break;
			scanf("%d %d",&a,&b);
			if(oper[0]=='Q')printf("%d\n",findmax(a,b));
			else if(oper[0]=='C')insert(1,pos[e[a][1]],b);
			else Negate(a,b);
		}
	}
	return 0;
}

