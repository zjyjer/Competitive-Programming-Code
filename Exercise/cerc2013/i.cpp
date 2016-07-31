#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int maxn=10101;
int pos[maxn],sit[maxn],n;
int ansx[600000],ansy[600000],num;

void chg(int l,int r){
	ansx[num]=l;ansy[num++]=r-l+r-1;
}
void swp(int l,int r){
	swap(pos[l],pos[r]);
	swap(sit[pos[l]],sit[pos[r]]);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			pos[i]=num;
			sit[num]=i;
		}
		num=0;
		while(n>1){
			int p=sit[n];
			if(p<n-1){
				int x=n-p-2;
				chg(p,p+x/2+1);
				chg(p+1,p+x/2+2);
				swp(p,p+x/2+1);
				swp(p+x/2+1,p+x/2*2+2);
				p=sit[n];
			}
			if(p==n-1)chg(p,n),swp(p,n);
			if(sit[n]!=n)while(1);
			n--;
		}if(num>500000)return 0;
		printf("%d\n",num);
		for(int i=0;i<num;i++)printf("%d %d\n",ansx[i],ansy[i]);
	}
	return 0;
}
