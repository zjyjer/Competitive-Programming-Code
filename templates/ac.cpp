#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

struct trie
{
	char ch;
	int son,next,father,suffix;
	vector <int> danger;
};
trie a[510000];
int now,m;
void clear(int x)
{
	a[x].son=a[x].next=0;
	a[x].danger.clear();
}
void insert(char *s,int l,int t,int x)
{
	if(!a[x].son)
	{
		a[x].son=++m;
		clear(m);
		a[m].father=x;
		a[m].ch=s[t];
		if (t+1==l)
			a[m].danger.push_back(now);
		else
			insert(s,l,t+1,m);
		return;
	}
	int i=a[x].son;
	while(1)
	{
		if(!a[i].next || a[i].ch == s[t])
			break;
		i=a[i].next;
	}
	if(a[i].ch==s[t] && t+1==l)
		a[i].danger.push_back(now);
	else if (a[i].ch==s[t])
		insert(s,l,t+1,i);
	else
	{
		a[i].next=++m;
		clear(m);
		a[m].father=x;
		a[m].ch=s[t];
		if (t+1==l)
			a[m].danger.push_back(now);
		else
			insert(s,l,t+1,m);
	}
}
int q[600000];
int child(int x,char ch)
{
	for (int i=a[x].son;i;i=a[i].next)
		if(a[i].ch==ch)
			return (i);
	if(x==1)
		return (1);
	return(child(a[x].suffix,ch));
}
void build_trie()
{
	int l,r;
	l=r=1;
	q[1]=1;
	while(l<=r)
	{
		int x=q[l++];
		for(int i=a[x].son;i;i=a[i].next)
			q[++r]=i;
	}
	a[1].suffix=1;
	for(int i=2;i<=r;i++)
	{
		int x=q[i];
		if(a[x].father==1)
		{
			a[x].suffix=1;
			continue;
		}
		a[x].suffix=child(a[a[x].father].suffix,a[x].ch);
//		for(int j=0;j<a[a[x].suffix].danger.size();j++)
//			a[x].danger.push_back(a[a[x].suffix].danger[j]);
	}
}

int query(char* str)
{
	int ans=0;
	int len=strlen(str);
	int cur=1;
	for(int i=0;i<len;i++)
	{
		while(1)
		{
			cur=child(cur,str[i]);
			if(cur==1) break;
			else
			{
			if(a[cur].danger.size()>0)
			
				ans+=a[cur].danger.size();
				a[cur].danger.clear();
				for(int j=a[cur].suffix;j!=1&&a[j].danger.size()!=0;j=a[j].suffix)
				{
					ans+=a[j].danger.size();
					a[j].danger.clear();
				}
				break;
			}
			if(cur==1)
				break;
		}
	}
	return ans;
}




char s[100];
char str[1000100];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		clear(m=1);
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			now=i;
			insert(s,strlen(s),0,1);
		}
		build_trie();
//		for(int i=1;i<=m;i++)
//		cout << a[i].ch <<" " << a[a[i].suffix].ch<< endl;
		scanf("%s",str);
		printf("%d\n",query(str));
	}
	return 0;
}
