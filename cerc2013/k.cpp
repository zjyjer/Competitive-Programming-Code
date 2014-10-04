#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int a[30][30];
int n;
int pre[50][30],q[2000],f,r,ct,path[50];

int work(){
	f=r=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<26;i++)q[f++]=i;
	ct=0;
	while(f!=r){
		if(ct>44)break;ct++;
		int tmp=f;
		for(int i=r;i<tmp;i++){
			for(int j=0;j<26;j++)
				if(a[q[i]][j]&&pre[ct][j]==-1){
					pre[ct][j]=q[i];q[f++]=j;
				}
		}
		r=tmp;
	}ct--;
	int p;
	for(p=0;p<27;p++)if(pre[ct][p]!=-1)break;
	for(int i=ct;i+1;i--){
		path[i]=p;p=pre[i][p];
	}
	return (ct)/2+1;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		memset(a,-1,sizeof(a));
		while(n--){
			char ch[3];cin>>ch;
			a[ch[0]-'a'][ch[1]-'a']=0;
		}
		int ans=work();ans=min(ans,20);
		for(int i=0;i<ans;i++){
			for(int j=0;j<ans;j++)cout<<(char)('a'+path[i+j]);cout<<endl;
		}
	}
	return 0;
}
