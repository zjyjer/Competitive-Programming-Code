#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define maxn 250005
#define eps 1e-8
#define zero(a) fabs(a)<eps
using namespace std;
char str[maxn];
char s[maxn];
int p[maxn];
int Manacher(char *s,int n){
    p[0]=p[1]=1;
    int mx=1,id=1,ans=1;
    for(int i=2;i<n;i++){
        if(mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        for(;s[i-p[i]]==s[i+p[i]];p[i]++);
        if(i+p[i]>mx){
            mx=i+p[i];
            id=i;
        }
        ans=max(ans,p[i]);
    }
    return ans-1;
}
int main(){
    while(scanf("%s",str)!=EOF){
        int l=strlen(str);
        s[0]='@';
        for(int i=0;i<l;i++){
            s[2*i+1]='#';
            s[2*i+2]=str[i];
        }
        s[2*l+1]='#';
        printf("%d\n",Manacher(s,2*l+2));
    }
    return 0;
}
