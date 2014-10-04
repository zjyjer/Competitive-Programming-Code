#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[40][40];
int n;

int gauss()
{
	int k, col;
	for(k = 0, col = 0; k < n && col < n; k++, col++)
	{
		int pivot = k;
		for(int i = k + 1; i < n; i++)
			if(a[i][col] > a[k][col])
				pivot = i;
		if(a[pivot][col] == 0)
		{
			k--;
			continue;
		}

		if(pivot != k)
			for(int i = col; i <= n; i++)
				swap(a[pivot][i], a[k][i]);

		for(int i = k + 1; i < n; i++)
			if(a[i][col])
				for(int j = col; j <= n; j++)
					a[i][j] ^= a[k][j];
	}

	for(int i = k; i < n; i++)
		if(a[i][col])
			return -1;
	return (1 << (n - k));
}
int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i][n]);
		int tmp;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			a[i][n] ^= tmp;
			a[i][i] = 1;
		}
		int l, r;
		while(scanf("%d %d", &l, &r)==2)
		{
			if(l == 0 && r == 0) 
				break;
			a[r - 1][l - 1] = 1;
		}
		int ans = gauss();
		if(ans < 0)
			printf("Oh,it's impossible~!!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
