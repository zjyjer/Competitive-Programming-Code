#include<iostream>
#include<string.h>
#include<stdio.h>
#define type int
#define MAXN 565
#define MAXM 510005
using namespace std;
class Edge
{
public:
    int from,to;
    type val;
    Edge(int a=0,int b=0,type c=0)
    {
        from=a;
        to=b;
        val=c;
    }
};
Edge edge[MAXM];
int pre[MAXN],id[MAXN];
type in[MAXN];
int vis[MAXN];
int MST(int root,int n,int m)
{
    int cost=0;
    while(1)
    {
        memset(in,0x7f,sizeof(in));
        for(int i=0;i<m;i++)
        {
            if(edge[i].val<in[edge[i].to]&&edge[i].from!=edge[i].to)
            {
                pre[edge[i].to]=edge[i].from;
                in[edge[i].to]=edge[i].val;
            }
        }
        for(int i=0;i<n;i++)
            if(i!=root&&in[i]==0x7f7f7f7f)return -1;
        int cntnode=0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        in[root]=0;
        for(int i=0;i<n;i++)
        {
            cost+=in[i];
            int v=i;
            while(vis[v]!=i&&v!=root&&id[v]==-1)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&id[v]==-1)
            {
                for(int j=pre[v];j!=v;j=pre[j])id[j]=cntnode;
                id[v]=cntnode++;
            }
        }
        if(cntnode==0)break;//无环
        for(int i=0;i<n;i++)if(id[i]==-1)id[i]=cntnode++;
        for(int i=0;i<m;i++)
        {
            int from=edge[i].from,to=edge[i].to;
            edge[i].from=id[from];
            edge[i].to=id[to];
            if(edge[i].from!=edge[i].to)edge[i].val-=in[to];
        }
        n=cntnode;
        root=id[root];
    }
    return cost;
}


int nn,mm,a[55],sum[55];

int main() {
    int m=0;
    sum[0]=0;
    while(~scanf("%d%d",&nn,&mm))  {
        m=0;
        if(nn==0&&mm==0)break;
        for(int i=1;i<=nn;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i]+1;
            edge[m].from=0;edge[m].to=sum[i-1]+1;edge[m++].val=0;
            for(int j=sum[i];j>sum[i-1]+1;j--){
                edge[m].from=j;edge[m].to=j-1;edge[m++].val=0;
            }
        }
        int c,d,l1,l2,v;
        while(mm--){
            scanf("%d%d%d%d%d",&c,&l1,&d,&l2,&v);
            //cin>>c>>l1>>d>>l2>>v;
            edge[m].from=sum[c-1]+1+l1;edge[m].to=sum[d-1]+1+l2;edge[m++].val=v;
            //graph[sum[c-1]+1+l1][sum[d-1]+1+l2]=min(graph[sum[c-1]+1+l1][sum[d-1]+1+l2],v);
        }

        int n=sum[nn]+1;
        int ans=MST(0,n,m);
        printf("%d\n",ans);
    }
    return 0;
}
