#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int n=15;
const double eps=1e-5;
char s[n];
int next[n];
long long a[n][n];
int m,N;
long long ans[n];
int vis[n<<1];
void kmp()
{
	memset(next,-1,sizeof(next));
	int j=-1;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		while(j!=-1 && s[i]!=s[j]) j=next[j];
		next[i+1]=++j;
	}
	next[0]=0;
}

void solve()
{
	kmp();
	vector<int> vec;
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(!vis[s[i]-'A'])
		{
			vec.push_back(s[i]-'A');
			vis[s[i]-'A']=1;
		}
	}
	int mm=vec.size();
	for(int i=0;i<len;i++)
	{
		a[i][i]-=N;
		a[i][len+1]=N;
		a[i][0]+=N-mm;
		for(int j=0;j<mm;j++)
		{
			int x=vec[j];
			if(x==s[i]-'A') a[i][i+1]++;
			else{
				int k=next[i];
				while(k && s[k]-'A'!=x) k=next[k];
				if(s[k]-'A'==x) a[i][k+1]++;
				else a[i][0]++;
			}
		}
	}
}

inline void gauss(long long a[][n],long long ans[])
{
	int res=0,r=0;
	for(int i=0;i<m;i++)
	{
		for(int j=r;j<m;j++)
			if(fabs(a[j][i])>eps){
				for(int k=i;k<=m;k++)
					swap(a[j][k],a[r][k]);
				break;
			}
			if(fabs(a[r][i])<eps)
			{
				++res;
				continue;
			}
			for(int j=0;j<m;j++)

				if(j!=r && fabs(a[j][i])>eps)
				{
					long long tmp=a[j][i]/a[r][i];
					for(int k=i;k<=m;k++)
						a[j][k]-=tmp*a[r][k];
				}
				r++;
			}
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(fabs(a[j][i])>=eps)
					{
						ans[i]=a[j][m]/a[j][i];
						//printf(" %d\n",ans[i]);
					}
				}
			}
		}
		int main()
		{
			int t;
			scanf("%d",&t);
			for(int cas=1;cas<=t;cas++)
			{
				printf("Case %d:\n",cas);
				scanf("%d",&N);
				scanf("%s",s);
				int len=strlen(s);
				m=++len;
				solve();
				/*
				for(int i=0;i<=m;i++)
				{
					for(int j=0;j<=m;j++)
						printf("%d ",a[i][j]);
					printf("\n");
				}*/
					memset(ans,0,sizeof(ans));
				gauss(a,ans);
				printf("%lld\n\n",-ans[0]);
			}
			return 0;
		}
