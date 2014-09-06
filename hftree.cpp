//区间第k小
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

#define N 100500 

#define MID ((l+r)>>1) 
int a[N],s[N],t[20][N],num[20][N],n,m; 

void Build(int c,int l,int r) 
{ 
	int lm=MID-l+1,lp=l,rp=MID+1; 
	for(int i=l;i<=MID;i++) 
		lm-=s[i]<s[MID]; 
	for(int i=l;i<=r;i++) 
	{ 
		if( i==l ) 
			num[c][i]=0; 
		else
			num[c][i]=num[c][i-1]; 
		if( t[c][i]==s[MID] ) 
		{ 
			if( lm ) 
			{ 
				lm--; 
				num[c][i]++; 
				t[c+1][lp++]=t[c][i]; 
			} 
			else
				t[c+1][rp++]=t[c][i]; 
		} 
		else if( t[c][i]<s[MID] ) 
		{ 
			num[c][i]++; 
			t[c+1][lp++]=t[c][i]; 
		} 
		else
			t[c+1][rp++]=t[c][i]; 
	} 
	if( l<r ) 
		Build(c+1,l,MID),Build(c+1,MID+1,r); 
} 

int Query(int c,int l,int r,int ql,int qr,int k) 
{ 
	if( l==r ) 
		return t[c][l]; 
	int s,ss; 
	if( l==ql ) 
		s=0,ss=num[c][qr]; 
	else
		s=num[c][ql-1],ss=num[c][qr]-num[c][ql-1]; 
	if( k<=ss ) 
		return Query(c+1,l,MID,l+s,l+s+ss-1,k); 
	else
		return Query(c+1,MID+1,r,MID+1+ql-l-s,MID+1+qr-l-s-ss,k-ss); 
} 

int main() 
{ 
	int cas;
	cin >> cas;
	while(cas--)
	{
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++) 
	{ 
		scanf("%d",&a[i]); 
		s[i]=t[0][i]=a[i]; 
	} 
	sort(s+1,s+1+n); 
	Build(0,1,n); 
	while( m-- ) 
	{ 
		int l,r,k; 
		scanf("%d%d%d",&l,&r,&k); 
		printf("%d\n",Query(0,1,n,l,r,k)); 
	} 
	}
	return 0; 
}
