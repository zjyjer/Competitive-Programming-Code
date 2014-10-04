#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[40][40];
int ans[40];
const int n = 30;

void gauss()
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

		for(int i = 0; i < k; i++)
			if(a[i][col])
				for(int j = col; j <= n; j++)
					a[i][j] ^= a[k][j];

		for(int i = k + 1; i < n; i++)
			if(a[i][col])
				for(int j = col; j <= n; j++)
					a[i][j] ^= a[k][j];
	}
}

int main()
{
	int cass;
	scanf("%d", &cass);
	for(int cas = 1; cas <= cass; cas++)
	{
		memset(a, 0, sizeof(a));
		for(int i = 0; i < 30; i++)
		{
			scanf("%d", &a[i][30]);
			a[i][i] = 1;
		}

		for(int i = 0; i < 30; i++)
		{
			if(i == 0)
			{
				a[1][0] = 1;
				a[6][0] = 1;
			}
			else if(i == 5)
			{
				a[4][5] = 1;
				a[11][5] = 1;
			}
			else if(i == 24)
			{
				a[18][24] = 1;
				a[25][24] = 1;
			}
			else if(i == 29)
			{
				a[28][29] = 1;
				a[23][29] = 1;
			}
			else if(i < 5)
			{
				a[i-1][i] = 1;
				a[i+1][i] = 1;
				a[i + 6][i] = 1;
			}
			else if(i > 24) 
			{
				a[i-1][i] = 1;
				a[i+1][i] = 1;
				a[i-6][i] = 1;
			}
			else if(i % 6 == 0)
			{
				a[i+1][i] = 1;
				a[i-6][i] = 1;
				a[i+6][i] = 1;
			}
			else if(i % 6 == 5)
			{
				a[i+6][i] = 1;
				a[i-6][i] = 1;
				a[i-1][i] = 1;
			}
			else
			{
				a[i+1][i] = 1;
				a[i-1][i] = 1;
				a[i-6][i] = 1;
				a[i+6][i] = 1;
			}
		}
		gauss();
		printf("PUZZLE #%d\n", cas);	
		for(int i = 0; i < 30; i++)
		{
			printf("%d", a[i][30]);
			if(i % 6 == 5)
				printf("\n");
			else printf(" ");
		}
	}
	return 0;
}	

