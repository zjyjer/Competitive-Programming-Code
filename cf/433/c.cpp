#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int size=100011;
typedef long long ll;

ll a[size],n,m;
vector<ll>V[size];

int main(){
cin>>n>>m;
for(int i=1;i<=m;i++)cin>>a[i];
a[0]=a[1];a[m+1]=a[m];
for(int i=1;i<=m;i++){
if(a[i]!=a[i-1])V[a[i]].push_back(a[i-1]);
if(a[i]!=a[i+1])V[a[i]].push_back(a[i+1]);
}
for(int i=0;i<=n;i++)sort(V[i].begin(),V[i].end());
ll ans=0;
for(int i=0;i<=n;i++){
if(!V[i].size())continue;
ll pre=0;
for(int j=0;j<V[i].size();j++)
pre+=abs(V[i][j]-i);
ll cur=0,x;
x=V[i][V[i].size()/2];
for(int j=0;j<V[i].size();j++)
cur+=abs(V[i][j]-x);
ans=max(ans,-cur+pre);//cout<<i<<' '<<pre<<' '<<cur<<endl;
}
ll res=0;
for(int i=1;i<m;i++)
res+=abs(a[i]-a[i+1]);
cout<<res-ans<<endl;
}