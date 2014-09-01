#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 65535;
struct hash{
	int a,b,next;
}Hash[maxn << 1];
int flg[maxn + 66];
int top,idx;
void ins(int a,int b){
	int k = b & maxn;
	if(flg[k] != idx){
		flg[k] = idx;
		Hash[k].next = -1;
		Hash[k].a = a;
		Hash[k].b = b;
		return ;
	}
	while(Hash[k].next != -1){
		if(Hash[k].b == b) return ;
		k = Hash[k].next;
	}
	Hash[k].next = ++ top;
	Hash[top].next = -1;
	Hash[top].a = a;
	Hash[top].b = b;
}
int find(int b){
	int k = b & maxn;
	if(flg[k] != idx) return -1;
	while(k != -1){
		if(Hash[k].b == b) return Hash[k].a;
		k = Hash[k].next;
	}
	return -1;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ext_gcd(int a,int b,int& x,int& y){
	int t,ret;
	if (!b){x=1,y=0;return a;}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}
int Inval(int a,int b,int n){
	int x,y,e;
	ext_gcd(a,n,x,y);
	e=(LL)x*b%n;
	return e<0?e+n:e;
}
int pow_mod(LL a,int b,int c){LL ret=1%c;a%=c;while(b){if(b&1)ret=ret*a%c;a=a*a%c;b>>=1;}return ret;}
int BabyStep(int A,int B,int C){
	top = maxn; ++ idx; 
	LL buf=1%C,D=buf,K;
	int i,d=0,tmp;
	for(i=0;i<=100;buf=buf*A%C,++i)if(buf==B && i!=0)return i;
	while((tmp=gcd(A,C))!=1){ 
		if(B%tmp)return -1;
		++d;
		C/=tmp;
		B/=tmp;
		D=D*A/tmp%C;
	}
	int M=(int)ceil(sqrt((double)C));
	for(buf=1%C,i=0;i<=M;buf=buf*A%C,++i)ins(i,buf);
	for(i=0,K=pow_mod((LL)A,M,C);i<=M;D=D*K%C,++i){
		tmp=Inval((int)D,B,C);int w ;
		if(tmp>=0&&(w = find(tmp)) != -1)return i*M+w+d;
	}
	return -1;
}
int main(){
	int A,B,C;
	while(scanf("%d%d",&A,&C)!=EOF,A || C){ //A^x mod C = B
		B =1;
		int tmp=BabyStep(A,B,C);
		printf("%d\n",6*tmp+3);
		if(tmp<0)
			puts("No Solution");
		else printf("%d\n",tmp);
	}
	return 0;
}