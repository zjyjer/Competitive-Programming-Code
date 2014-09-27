#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=-99999999;
class Node
{
public:
	Node *child[2],*pre;
	int index,ma,num;
	Node()
	{
		child[0]=child[1]=NULL;
		pre=NULL;
		ma=num=-0x7fffffff;
	}
};
Node *root;
void rotate(Node *x,int c)
{
	Node *y=x->pre;
	y->child[!c]=x->child[c];
	if(x->child[c]!=NULL)
		x->child[c]->pre=y;
	x->pre=y->pre;
	if(y->pre!=NULL)
	{
		if(y->pre->child[0]==y)y->pre->child[0]=x;
		else y->pre->child[1]=x;
	}
	x->child[c]=y;
	y->pre=x;
	if(y==root)root=x;
	(*y).ma=max(y->num,max((y->child[0]==NULL?INF:y->child[0]->ma),(y->child[1]==NULL?INF:y->child[1]->ma)));
}

void splay(Node *x,Node *f)
{
	while(x->pre!=f)
	{
		Node *y=x->pre,*z=y->pre;
		if(x->pre->pre==f)rotate(x,x->pre->child[0]==x);
		else
		{
			if(z->child[0]==y)
			{
				if(y->child[0]==x)rotate(y,1),rotate(x,1);
				else rotate(x,0),rotate(x,1);
			}
			else
			{
				if(y->child[1]==x)rotate(y,0),rotate(x,0);
				else rotate(x,1),rotate(x,0);
			}
		}
	}
	//(*x).sum=y->num+(x->child[0]==NULL?0:x->child[0]->sum)+(x->child[1]==NULL?0:x->child[1]->sum);
	(*x).ma=max(x->num,max((x->child[0]==NULL?INF:x->child[0]->ma),(x->child[1]==NULL?INF:x->child[1]->ma)));
}
int n,m,a,b;
char ch[2];
void insert(int pos,int val=INF)
{
	Node *p=root,*q=NULL;
	while(p)
	{
		q=p;
		p=p->child[p->index<pos];
	}
	p=new Node();
	p->index=pos,p->num=p->ma=val;
	if(!q)
	{
		root=p;
		return;
	}
	q->child[q->index<pos]=p;
	if(p)p->pre=q;
	splay(p,NULL);
}
Node* find(int k)
{
	Node *p=root;
	while(p->index!=k)
	{
		if(p->index<k)p=p->child[1];
		else p=p->child[0];
	}
	splay(p,NULL);
	return p;
}
int query(int l,int r)
{
	if(l>r)swap(l,r);
	Node *p=find(l-1),*q=find(r+1);
	splay(p,q);
	return p->child[1]->ma;
}
void update(int x,int y)
{
	find(x);
	root->num=y;
	(*root).ma=max(root->num,max((root->child[0]==NULL?INF:root->child[0]->ma),(root->child[1]==NULL?INF:root->child[1]->ma)));
}
void del(Node *p)
{
	if(p==NULL)return;
	del(p->child[0]);
	del(p->child[1]);
	delete p;
	return;
}
int main()
{
	root=NULL;
	while(~scanf("%d%d",&n,&m))
	{
		insert(0);
		insert(n+1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			insert(i,a);
		}
		while(m--)
		{
			scanf("%s%d%d",ch,&a,&b);
			if(ch[0]=='Q')printf("%d\n",query(a,b));
			else update(a,b);
		}
		del(root);
		root=NULL;
	}
	return 0;
}
