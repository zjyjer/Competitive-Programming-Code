#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 100010;
long long a[2][maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
			scanf("%I64d", &a[0][i]);
		int start = 1, end = n, s = 0;
		bool finish;
		for(int i = 1; i < n; i++,s^=1)
		{
			while(start < end && a[s][start] == 0)
				start++;
			start = std::max(start - 1, 1);
			while(start < end && a[s][end] == 0)
				end--;
			end = std::min(n - i + 1, end + 1);
			if(start >= end)
			{
				break;
			}
			int dec = 1, inc = 1;
			for(int j = start; j < end; j++)
			{
				if(a[s][j+1] > a[s][j]) dec = 0;
				if(a[s][j+1] < a[s][j]) inc = 0;
			}
			finish = inc | dec;
			if(!finish)
			{
				if(i == 1)
					puts("ugly series");
				else
					printf("%d\n",i-2);
				break;
			}
			for(int j = start; j < end; j++)
			{
				a[s^1][j]=a[s][j+1] - a[s][j];
			}
			end --;
		}
		if(finish)
			puts("nice series");
	}
	return 0;
}