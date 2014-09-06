#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q;
int l,r,k;
int s;
int a[200010];
int cur1,cur2;

struct Node
{
	int* p;
	int num;
	int l,r;
}node[200010];

void init()
{
	s = 1;
	while(s <= n)
		s*=2;
	for(int j=s;j<s*2;j++)
	{
		node[j].p=new int[1];
		node[j].p[0]=a[j-s];
		node[j].num=1;
		node[j].l=j-s+1;
		node[j].r=j-s+1;
	}
}

void pre()
{
	for(int j=s-1;j>=1;j--)
	{
		cur1=cur2=0;
		int len=node[2*j].num;
		node[j].p=new int[len*2];
		int lchild=2*j;
		int rchild=lchild+1;
		int cur=0;
		while(cur1<len && cur2<len)
		{
			if(node[lchild].p[cur1]<node[rchild].p[cur2])	
				node[j].p[cur++]=node[lchild].p[cur1++];
			else
				node[j].p[cur++]=node[rchild].p[cur2++];
		}
		if(cur1!=len)
		{
			while(cur1<len)
				node[j].p[cur++]=node[lchild].p[cur1++];
		}
		if(cur2!=len)
		{
			while(cur2<len)
				node[j].p[cur++]=node[rchild].p[cur2++];
		}
		node[j].num=len*2;
		node[j].l=node[lchild].l;
		node[j].r=node[rchild].r;
	}
}

int counthelp(int l,int r,int p,int key,int deep)
{
	int mid;
	while(l<=r)
	{
		mid = (l+r)>>1;
		if(node[p].p[mid]<key)
			l=mid+1;
		else
			r=mid-1;
	}
	return r-node[p].l+1;
}
int count(int l,int r,int p,int key,int deep)
{
	if(node[p].l==l && node[p].r==r)
	{
		return counthelp(l,r,p,key,deep);
	}
	if(r<=((node[p].l+node[p].r)>>1))
		return count(l,r,p*2,key,deep+1);
	else if(l>((node[p].l+node[p].r)>>1))	
		return count(l,r,p*2+1,key,deep+1);
	else
	{
		return count(l,(node[p].l+node[p].r)>>1,p*2,key,deep+1)+count(((node[p].l+node[p].r)>>1)+1,r,p*2+1,key,deep+1);
	}
}
int query(int ll,int rr,int cnt)
{
	int mid,tmp;
	int l=0;
	int r=s-1;
	while(l<=r)
	{
		mid = (l+r)>>1;
//		cout << mid << endl;
		tmp = count(ll,rr,1,node[1].p[mid],1);
		cout << ll << " " << rr << " " << node[1].p[mid] << " " << tmp << endl;
		if(tmp>=cnt)
			r=mid-1;
		else
			l=mid+1;
	}
	return node[1].p[l-1];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&q);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		init();
		pre();
//		for(int i=1;i<=32;i++)
//		{
//			for(int j=1;j<=node[1].num;j++)
//				printf("%d ",node[1].p[j-1]);
//			printf("\n");
//		}
		for(int i=0;i<q;i++)
		{
			scanf("%d %d %d",&l,&r,&k);		
			printf("%d\n",query(l,r,k));
		}
		
	}
	return 0;
}
