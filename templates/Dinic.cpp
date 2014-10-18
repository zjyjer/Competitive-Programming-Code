#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

const int size=-1,M=0;
int lev[size],q[size],cur[size],f,inf=1000000;
int head[size],tot;
struct node{
	int next,c,to;
}E[M];
struct Max_flow{
	int S,T,n;
	void init(){
		tot=0;
		for(int i=0;i<=n;i++)head[i]=-1;
	}

	void add(int a,int b,int c){
		E[tot].next=head[a];
		E[tot].to=b;
		E[tot].c=c;
		head[a]=tot++;
	}

	void dadd(int a,int b,int c){
		add(a,b,c);
		add(b,a,0);
	}

	void build(){

	}

	int bfs(){
		for(int i=0;i<=n;i++)lev[i]=0;
		lev[S]=1;
		f=0;
		q[f++]=S;
		for(int i=0;i<f;i++){
			int u=q[i];
			for(int i=head[u];i!=-1;i=E[i].next)
			if(lev[E[i].to]==0&&E[i].c>0){
				int to=E[i].to;
				lev[to]=lev[u]+1;
				q[f++]=to;
				if(to==T)return 1;
			}
		}
		return 0;
	}

	int dfs(int u,int f){
		if(u==T)return  f;
		int tag=0,c;
		for(int &i=cur[u];i!=-1;i=E[i].next){
			int to=E[i].to;
			if(E[i].c>0&&lev[to]==lev[u]+1){
				c=dfs(to,min(f-tag,E[i].c));
				E[i].c-=c;
				E[i^1].c+=c;
				tag+=c;
				if(tag==f)return tag;
			}
		}
		return tag;
	}

	int solve(){
		int ans=0;
		while(bfs()){
			for(int i=0;i<=n;i++)cur[i]=head[i];
			ans+=dfs(S,inf);
		}
		return ans;
	}
}F;
