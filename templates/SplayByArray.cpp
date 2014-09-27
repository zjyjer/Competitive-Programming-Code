#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
const int INF=0x3fffffff;
class Node
{
public:
	int child[2],pre;
	int size,num,lazy;
	Node()
	{
		child[0]=child[1]=pre=0;
		lazy=0;
	}
};
Node node[500005];
int mem;
int newNode()
{
	node[mem]=Node();
	return mem++;
}
class Splay
{
public:
	int root;
	Splay()
	{
		root=0;
	}
	void push_up(int x)
	{
		if(!x)return;
		node[x].size=node[node[x].child[0]].size+
			node[node[x].child[1]].size+1;
	}
	void push_down(int x)
	{
		if(!x)return;
		if(node[x].lazy)
		{
			if(node[x].child[0])
				node[node[x].child[0]].lazy^=1;
			if(node[x].child[1])
				node[node[x].child[1]].lazy^=1;
			swap(node[x].child[0],node[x].child[1]);
			node[x].lazy=0;
		}
	}
	void rotate(int x,int c)
	{
		int y=node[x].pre;
		push_down(y),push_down(x);
		node[y].child[!c]=node[x].child[c];
		if(node[x].child[c])
			node[node[x].child[c]].pre=y;
		node[x].pre=node[y].pre;
		if(node[y].pre)
		{
			if(node[node[y].pre].child[0]==y)
				node[node[y].pre].child[0]=x;
			else node[node[y].pre].child[1]=x;
		}
		node[x].child[c]=y;
		node[y].pre=x;
		if(y==root)root=x;
		push_up(y);
	}
	void splay(int x,int f)
	{
		push_down(x);
		while(node[x].pre!=f)
		{
			int y=node[x].pre,z=node[y].pre;
			if(node[node[x].pre].pre==f)
				rotate(x,node[node[x].pre].child[0]==x);
			else
			{
				if(node[z].child[0]==y)
				{
					if(node[y].child[0]==x)rotate(y,1),rotate(x,1);
					else rotate(x,0),rotate(x,1);
				}
				else
				{
					if(node[y].child[1]==x)rotate(y,0),rotate(x,0);
					else rotate(x,1),rotate(x,0);
				}
			}
		}
		push_up(x);
	}
	int find(int pos)
	{
		int p=root;
		push_down(p);
		int s=node[node[p].child[0]].size;
		while(pos!=s+1)
		{
			if(pos<=s)p=node[p].child[0];
			else
			{
				pos-=(s+1);
				p=node[p].child[1];
			}
			push_down(p);
			s=node[node[p].child[0]].size;
		}
		splay(p,0);
		return p;
	}
};
int n,m,a,b,c,t;
char ch[20];
int arr[310005];
void get(int r)
{
	if(!r)return;
	Splay().push_down(r);
	get(node[r].child[0]);
	arr[t++]=node[r].num;
	get(node[r].child[1]);
}
int build(int left,int right)
{
	if(left>right)return 0;
	int mid=(left+right)/2;
	int r=newNode();
	node[r].num=mid-1;
	node[r].child[0]=build(left,mid-1);
	node[r].child[1]=build(mid+1,right);
	if(node[r].child[0])node[node[r].child[0]].pre=r;
	if(node[r].child[1])node[node[r].child[1]].pre=r;
	Splay().push_up(r);
	return r;
}
int main()
{
	while(scanf("%d%d",&n,&m)&&n>0)
	{
		mem=1;
		Splay s;
		s.root=build(1,n+2);
		while(m--)
		{
			scanf("%s %d %d",ch,&a,&b);
			if(ch[0]=='C')
			{
				scanf("%d",&c);
				int p=s.find(a),q=s.find(b+2);
				s.splay(p,q);
				int cut=node[node[s.root].child[0]].child[1];
				node[node[s.root].child[0]].child[1]=0;
				s.push_up(node[s.root].child[0]);
				s.push_up(s.root);
				p=s.find(c+1),q=s.find(c+2);
				s.splay(p,q);
				node[node[s.root].child[0]].child[1]=cut;
				node[cut].pre=node[s.root].child[0];
				s.push_up(node[s.root].child[0]);
				s.push_up(s.root);
			}
			else
			{
				int p=s.find(a),q=s.find(b+2);
				s.splay(p,q);
				node[node[node[s.root].child[0]].child[1]].lazy^=1;
			}
		}
		t=0;
		get(s.root);
		for(int i=1;i<n;i++)printf("%d ",arr[i]);
		printf("%d\n",arr[n]);
	}
	return 0;
}
	
