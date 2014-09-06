#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#define MAXN 100002
#define MLOG 19
using namespace std;
int tree[MLOG][MAXN],cntleft[MLOG][MAXN],sorted[MAXN];
void buildtree(int lef,int rig,int deep)
{
	if(lef==rig)return;
	int mid=(lef+rig)>>1,same=0,lpos=lef,rpos=mid+1;
	for(int i=lef;i<=rig;i++)
		if(tree[deep][i]<sorted[mid])same++;
	same=mid-lef+1-same;
	for(int i=lef;i<=rig;i++)
	{
		if(tree[deep][i]<sorted[mid]||
				(tree[deep][i]==sorted[mid]&&(same--)>0))
		{
			tree[deep+1][lpos++]=tree[deep][i];
			cntleft[deep][i]=cntleft[deep][i-1]+1;
		}
		else
		{
			tree[deep+1][rpos++]=tree[deep][i];
			cntleft[deep][i]=cntleft[deep][i-1];
		}
	}
	buildtree(lef,mid,deep+1);
	buildtree(mid+1,rig,deep+1);
}
int query(int lef,int rig,int qlef,int qrig,int deep,int k)
{//区间总长l,r，查询ql至qr到第k小数
	while(lef<rig)
	{
		int mid=(lef+rig)>>1,newl,newr;
		int temp=cntleft[deep][qrig]-cntleft[deep][qlef-1];
		if(temp>=k)
		{
			newl=cntleft[deep][qlef-1]-cntleft[deep][lef-1]+lef;
			newr=newl+temp-1;
			return query(lef,mid,newl,newr,deep+1,k);
		}
		else
		{
			newr=qrig+cntleft[deep][rig]-cntleft[deep][qrig];
			newl=newr-(qrig-qlef-temp);
				return query(mid+1,rig,newl,newr,deep+1,k-temp);
		}
	}
	return tree[deep][qlef];
}
int nextint()
{
	bool flag=0;
	char ch;
	while(ch=getchar())
	{
		if(ch=='-')
			flag=1;
		if(ch>='0'&&ch<='9')
			break;
	}
	int ans=ch-'0';
	while(ch=getchar())
	{
		if(ch<'0'||ch>'9')break;
		ans*=10,ans+=ch-'0';
	}
	if(flag==1)
		ans=-ans;
	return ans;
}
//注意初始化cntleft，排序sorted，buildtree(1,n,0)
int main()
{
	int cas;
	cas=1;
	while(cas--)
	{
		memset(cntleft,0,sizeof(cntleft));
		int n,m;
		n=nextint();
		m=nextint();
		for(int i=1;i<=n;i++)
		{
			sorted[i]=nextint();
			tree[0][i]=sorted[i];
		}
		sort(sorted+1,sorted+n+1);
		buildtree(1,n,0);
		int a,b,c;
		for(int i=0;i<m;i++)
		{
			a=nextint();
			b=nextint();
			c=nextint();
			printf("%d\n",query(1,n,a,b,0,c));
		}
	}
	return 0;
}
