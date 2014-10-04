#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int a[300][300];
int ans[300];
char ch[300][300];
int n, sqr;

int gauss()
{
	int k, col;
	for(k = 1, col = 1; k <= sqr && col <= sqr; k++, col++)
	{
		int pivot = k;
		for(int i = k + 1; i <= sqr; i++)
			if(a[i][col] > a[k][col])
				pivot = i;

		if(a[pivot][col] == 0)
		{
			k--;
			continue;
		}

		if(pivot != k)
			for(int i = col; i <= sqr + 1; i++)
				swap(a[pivot][i], a[k][i]);

		for(int i = 1; i <= sqr; i++)
			if(i != k && a[i][col])
				for(int j = col; j <= sqr + 1; j++)
					a[i][j] ^= a[k][j];
	}

	for(int i = k + 1; i <= sqr; i++)
		if(a[i][col])
			return -1;
	int free = sqr - k + 1;
	int sol = 10000;
	for(int s = 0; s < (1 << free) ; s++)
	{
		for(int j = 1; j <= k; j++)
		{
			for(int i = 0; i < free; i++)
			{
				if(s & (1 << (k + i)))
					a[j][sqr+1] ^= 1;
			}
		}
		int tmp = 0;
		for(int i = 1; i <= k; i++)
			if(a[i][sqr+1])
				tmp++;
		sol = min(sol, tmp);
	}
	return sol;
}
int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", ch[i]+1);
		}

		memset(a, 0, sizeof(a));
		sqr = n * n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(ch[i][j] == 'w')
					a[n * (i - 1) + j][sqr+1] = 1;
		for(int i = 1; i <= sqr; i++)
			a[i][i] = 1;

		for(int i = 1; i <= sqr; i++)
		{
			if(i % n != 0)
				a[i+1][i] = 1;
			if(i % n != 1)
				a[i-1][i] = 1;
			if(i > n)
				a[i-n][i] = 1;
			if(i <= sqr - n)
				a[i+n][i] = 1;
		}

		int ans = gauss();
		if(ans < 0)
			printf("inf\n");
		else printf("%d\n", ans);
	}
	return 0;
}	
