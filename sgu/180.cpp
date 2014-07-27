#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct Node
{
	long long val;
	int id;
}node[70000];

long long bit[70000],t[70000];

int lowbit(int n)
{
	return n&(-n);
}

void add(int a,int k)
{
	while(a<=n)
	{
		bit[a]+=k;
		a+=lowbit(a);
	}
}

long long sum(int a)
{
	long long ret=0;
	while(a>0)
	{
		ret+=bit[a];
		a-=lowbit(a);
	}
	return ret;
}

bool cmp(Node a,Node b)
{
	if(a.val!=b.val)
		return a.val<b.val;
	else return a.id<b.id;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> node[i].val;
		node[i].id=i;
	}
	sort(node+1,node+n+1,cmp);
	int jj=0;
	node[0].val=-11000;
	for(int i=1;i<=n;i++)
	{
		if(node[i].val!=node[i-1].val)
			jj++;
		t[node[i].id]=jj;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		add(t[i],1);
		ans+=i-sum(t[i]);
	}
	cout << ans << endl;
	return 0;
}