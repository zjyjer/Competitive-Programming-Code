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

const int N=0,M=0,inf=1000000000;
struct node{
	int to,next,c,w;
}E[M];
int head[N],tot,que[N],dis[N],vis[N],pre[N];

struct MinCostFlow {
/*
	NODE:
		remember to init S,T,n,inf ;
		use add and dadd correctly ;
		change min and max cost ;
*/
    int S,T,n;//  max_size

    void init(){
		//S=T=n=-1;
		for(int i=0;i<=n;i++) head[i]=-1;
		tot=0;
    }

    void add(int a,int b,int c,int w){
		E[tot].next=head[a];
		E[tot].to=b;
		E[tot].c=c;
		E[tot].w=w;
		head[a]=tot++;
    }
    void dadd(int a,int b,int c,int w){
		add(a,b,c,w);
		add(b,a,0,-w);
    }

    bool spfa(){                  //  源点为0，汇点为n。
		int i, front = 0, tail = 1;
		for(i = 0; i <= n; i ++){
			dis[i] = inf;
			vis[i] = false;
		}
		dis[S] = 0;
		que[0] = S;
		vis[S] = true;
		while(tail != front){       //  这里最好用队列，有广搜的意思，堆栈像深搜。
			int u = que[front ++];
			front %= N;

			for(i = head[u]; i != -1; i = E[i].next){
				int v = E[i].to;
				if(E[i].c && dis[v] > dis[u] + E[i].w){
					dis[v] = dis[u] + E[i].w;
					pre[v] = i;
					if(!vis[v]){
						vis[v] = true;
						que[tail ++] = v;
						tail %= N;
					}
				}
			}
			vis[u] = false;
		}
		if(dis[T] == inf) return false;
		return true;
	}

	int end(int &flow){
		int u, p, sum = inf, ans = 0;
		for(u = T; u != S; u = E[p^1].to){
			p = pre[u];
			sum = min(sum, E[p].c);
		}
		for(u = T; u != S; u = E[p^1].to){
			p = pre[u];
			E[p].c -= sum;
			E[p^1].c += sum;
			ans += sum * E[p].w;     //  cost记录的为单位流量费用，必须得乘以流量。
		}
		flow += sum;
		return ans;
	}

	int solve(){
		int ans = 0, flow = 0;
		while(spfa()){
			ans+=end(flow);
		}
		return ans;
	}

};
