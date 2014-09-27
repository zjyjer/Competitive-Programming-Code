#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
#define head 0
#define N 50000
#define INF 0x7f7f7f7f
long long aabs(long long x){
    if(x<0)x=-x;
    return x;
}
class Node
{
public:
    long long x,y;
    Node(long long a=0,long long b=0){
        x=a,y=b;
    }
    long long dis(Node b){
        return aabs(x-b.x)+aabs(y-b.y);
    }
};
Node node[222];
int U[N],D[N],L[N],R[N];
int C[N],H[N],V[1000],ans[N];
long long dis[66][66];
bool mark[66];
int Num,rownum,colnum;
void remove(int c){
    for(int i=D[c];i!=c;i=D[i])
        R[L[i]]=R[i],L[R[i]]=L[i];
}
void resume(int c){
    for(int i=D[c];i!=c;i=D[i])
        R[L[i]]=L[R[i]]=i;
}

int gujia(){
    int ans=0;
    memset(mark,0,sizeof(mark));
    for(int c=R[0];c!=0;c=R[c])
        if(!mark[c])
        {
            ans++;
            for(int i=D[c];i!=c;i=D[i])
                for(int j=R[i];j!=i;j=R[j])
                    mark[C[j]]=1;
        }
    return ans;
}
bool dance(int k){
    int c=R[head];
    if(c==head)return true;
    if(k<gujia())return false;
    if(k==0)return false;
    int m=INF,pp=c;
    for(int i=c; i!=head; i=R[i])
        if(V[i]<m&&V[i]>1)m=V[i],pp=i;
    c=pp;
    if(m==INF)return false;
    for(int i=D[c]; i!=c; i=D[i])
    {
        remove(i);
        for(int j=R[i]; j!=i; j=R[j])remove(j);
        if(dance(k-1))return true;
        for(int j=L[i]; j!=i; j=L[j])resume(j);
        resume(i);
    }
    return false;
}
void newnode(int num,int l,int u,int r,int d,int h,int c)
{
    L[num]=l;U[num]=u;
    R[num]=r;D[num]=d;
    L[R[num]]=num;R[L[num]]=num;
    U[D[num]]=num;D[U[num]]=num;
    H[num]=h;C[num]=c;
    V[c]++;
}
void init(int t){
    memset(V,0,sizeof(V));
    Num=0;
    rownum=1;
    colnum=t;
    newnode(Num++,0,0,0,0,0,0);
    for(int i=1; i<=t; i++)
        newnode(Num++,i-1,i,0,i,0,i);
}
int t,n,k;
int main()
{
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%I64d %I64d",&node[i].x,&node[i].y);
        long long high=0,low=0,mid;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=node[i].dis(node[j]),
                high=max(high,dis[i][j]);
        while(low<high)
        {
            mid=(low+high)/2;
            init(n);
            for(int i=1;i<=n;i++)
            {
                bool flag=1;
                for(int j=1;j<=n;j++)
                    if(dis[i][j]<=mid)
                    {
                        if(flag)
                            newnode(Num,Num,U[C[j]],Num,C[j],rownum,j),flag=0;
                        else newnode(Num,Num-1,U[C[j]],R[Num-1],C[j],rownum,j);
                        Num++;
                    }
                if(!flag)rownum++;
            }
            if(dance(k))high=mid;
            else low=mid+1;
        }
        printf("Case #%d: %I64d\n",ca,low);
    }
    return 0;
}
