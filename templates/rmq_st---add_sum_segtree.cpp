#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;
const int size=100111;

int n,c[size][19];

void init(){
	for(int i=1;i<=n;i++)c[i][0]=a[i];
	for(int i=1;(1<<i)<=n;i++)
	for(int j=1;j<=n;j++){
		c[j][i]=c[j][i-1];
		if(j+(1<<(i-1))<=n)c[j][i]=gcd(c[j][i],c[j+(1<<(i-1))][i-1]);
	}
}
int get(int l,int r){
	int k=0;
	while(l+(1<<k)<=1+r)k++;
	k--;
	return gcd(c[l][k],c[r-(1<<k)+1][k]);
}
long long st[size*4],lz[size*4];
struct tree{
	void build(int p,int l,int r){
		st[p]=lz[p]=0;
		if(l!=r){
			build(p*2,l,(l+r)/2);
			build(p*2+1,(l+r)/2+1,r);
		}
	}
	int L,R,x;
	void down(int p,long long lzz,int l,int r){
		lz[p]+=lzz;
		st[p]+=lzz*(r-l+1);
	}
	void add(int p,int l,int r){
		if(L>r||R<l)return ;
		int mid=(l+r)/2;
		if(L<=l&&R>=r){
			lz[p]+=x;st[p]+=x*(r-l+1);return ;
		}
		else if(lz[p]){
			down(p*2,lz[p],l,mid);down(p*2+1,lz[p],mid+1,r);lz[p]=0;
		}
		add(p*2,l,mid);add(p*2+1,mid+1,r);
		st[p]=(st[p*2]+st[p*2+1]);
	}
	long long get(int p,int l,int r){
		if(L>r||R<l)return 0;
		int mid=(l+r)/2;
		if(L<=l&&R>=r){
			return st[p];
		}
		else if(lz[p]){
			down(p*2,lz[p],l,mid);down(p*2+1,lz[p],mid+1,r);lz[p]=0;
		}
		return get(p*2,l,mid)+get(p*2+1,mid+1,r);
	}
}T;

