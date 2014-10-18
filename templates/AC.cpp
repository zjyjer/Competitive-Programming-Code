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

const int size=555000;
char ch[1111111];

struct AC{
	/*
	  node:
			记住到新的节点的时候小心ＦＡＩＬ值
	*/
	int next[size][26],fail[size],end[size];
	int root,num,ind,x,tmp,ans;

	void Init(){
		memset(next[0],-1,sizeof(next[0]));
		root=num=0;
		fail[0]=end[0]=0;
	}

	void Insert(int n){
		while(n--){
			scanf("%s",ch);
			ind=0;
			for(int i=0;ch[i];i++){
				x=ch[i]-'a';
				if(next[ind][x]==-1){
					next[ind][x]=++num;
					memset(next[num],-1,sizeof(next[num]));
					end[num]=0;
				}
				ind=next[ind][x];
			}
			end[ind]++;
		}
	}

	void Build(){
		queue<int> q;
		for(int i=0;i<26;i++)
		if(next[0][i]==-1){
			next[0][i]=0;
		}
		else{
			fail[next[0][i]]=0;
			q.push(next[0][i]);
		}
		while(!q.empty()){
			ind=q.front();
			q.pop();
			for(int i=0;i<26;i++){
				x=next[ind][i];
				if(x!=-1){
					fail[x]=next[fail[ind]][i];
					q.push(x);
				}
				else next[ind][i]=next[fail[ind]][i];
			}
		}
	}

	void Solve(){
		scanf("%s",ch);
		ind=ans=0;
		for(int x=0;ch[x];x++){
			int i=ch[x]-'a';
			ind=next[ind][i];
			tmp=ind;
			while(tmp!=0&&end[tmp]!=-1){
				ans+=end[tmp];
				end[tmp]=-1;
				tmp=fail[tmp];
			}
		}
		printf("%d\n",ans);
	}

}T;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		T.Init();
		cin>>n;
		T.Insert(n);
		T.Build();
		T.Solve();
	}
}
