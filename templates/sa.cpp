#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200010;

char s[maxn];
int str[maxn], h[maxn], sa[maxn], rank[maxn];
int d[maxn][20];

// doubling
void radix(int *str, int *a, int *b, int n, int m)
{
	static int count[maxn << 1];
	memset(count, 0, sizeof(count));
	for(int i = 0; i < n; i++) count[str[a[i]]]++;
	for(int i = 1; i <= m; i++) count[i] += count[i - 1];
	for(int i = n-1; i >= 0; i--) b[--count[str[a[i]]]] = a[i];
}

void suffixarray(int *str, int *sa, int n, int m)
{
	static int a[maxn << 1], b[maxn << 1];
	for(int i = 0; i < n; i++) rank[i] = i;
	radix(str, rank, sa, n, m);
	rank[sa[0]] = 0;
	for(int i = 1; i < n; i++) rank[sa[i]] = rank[sa[i-1]] + (str[sa[i]]!=str[sa[i-1]]);
	for(int i = 0; (1<<i) < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			a[j] = rank[j] + 1;
			b[j] = j + (1 << i) >= n?0:rank[j+(1 << i)] + 1;
			sa[j] = j;
		}
		radix(b, sa, rank, n, n);
		radix(a, rank, sa, n, n);
		rank[sa[0]] = 0;
		for(int j = 1; j < n; j++)
		{
			rank[sa[j]] = rank[sa[j-1]] + (a[sa[j-1]]!=a[sa[j]] || b[sa[j-1]]!=b[sa[j]]);
		}
	}
}
//DC3

void calheight(int *str, int *sa, int *h, int n)
{
	int k = 0; h[0] = 0;
	for(int i = 0; i < n; i++)
	{
		if(k) k--;
		if(rank[i])
			while(str[i+k] == str[sa[rank[i]-1]+k]) k++;
		h[rank[i]] = k;
	}
}

void rmqinit(int n){
	for(int i=1;i<=n;i++)
		d[i][0]=h[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int query(int l,int r)
{
	int k=0;
	while((1<<(k+1)) <= r-l+1) k++;
	return min(d[l][k],d[r-(1<<k)+1][k]); 
}

int lcp(int a, int b)
{
	int t;
	a = rank[a]; b = rank[b];
	if(a > b)
		swap(a, b);
	return h[query(a+1, b)];
}

int main()
{
	//freopen("data.in", "r", stdin);
	int cas;
	scanf("%d", &cas);
	for(int i = 1; i <= cas; i++)
	{
		scanf("%s",s);
		int len1 = strlen(s);
		s[len1] = '$';
		scanf("%s",s+len1+1);
		printf("Case #%d:", i);
		int len2 = strlen(s);
		for(int i = 0; i < len2; i++)
			str[i] = s[i] ;
		suffixarray(str,sa,len2,200);
		calheight(str,sa,h,len2);
		int fir = 0, sec = len1 + 1;
		rmqinit(len2);
		bool flag = false;
		for(int j = 0; j < len1; j++)
		{
			int f = 0;
			sec = len1 + 1;
			fir = j;
			while(sec < len2 && f < 3)
			{
				int step = lcp(fir, sec);
				fir+=step;
				sec+=step;
				fir++; sec++;
				f++;
			}
			if(sec == len2)
				{
					flag = true;
					printf(" %d\n", j);
					break;
				}
		}
		if(!flag)
			printf(" -1\n");
	}
}
