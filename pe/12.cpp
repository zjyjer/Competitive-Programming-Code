#include <cstdio>

const int maxn = 50010;
int max(int a, int b)
{
	if(a < b) return b;
	else return a;
}

int div[maxn] = {0};

void init()
{
	for(int i = 1; i < maxn; i++)
	{
		int j;
		for(j = 1; j * j < i; j++)
			if(i % j == 0)
				div[i] += 2;
		if(j * j == i)
			div[i] ++;
	}
}

int ans[maxn] = {0};
int solve()
{
	for(int i = 1; i < maxn; i++)
		if(i % 2 == 0)
			ans[i] = div[i/2] * div[i + 1];
		else ans[i] = div[i] * div[(1 + i) / 2];
}

int main()
{
	int t;
	scanf("%d", &t);
	init();
	solve();
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i < maxn; i++)
			if(ans[i] > n)
			{
				printf("%d\n", i * (i + 1) / 2);
				break;
			}
	}
}
