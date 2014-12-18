#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 550000;
const int maxd = 20;

bool hash0[maxn] = {0};
int hash[maxn];
char str[maxn];
char ans[maxd];
bool vis[maxn][maxd] = {0};

void convert(int len, int x)
{
	int i;
	for(i = 0; i < len; i++)
		ans[i] = 'a';
	ans[len] = '\0';
	i = len - 1;
	while(x)
	{
		if(x & 1)
			ans[i] = 'b';
		x >>= 1;
		i--;
	}
}
int main()
{
	int len, tmp;
	scanf("%d%s", &len, str);
	for(int i = 0; i < len; i++)
	{
		tmp = str[i] - 'a';
		hash[i] = hash0[i] = tmp;
		vis[tmp][1] = 1;
	}
	for(int k = 2; k <= 19; k++)
	{
		for(int i = 0; i + k <= len; i++)
		{
			tmp = (hash[i] << 1) | hash0[i + k - 1];
			hash[i] = tmp;
			vis[tmp][k] = 1;
		}
	}
	for(int k = 1; k <= 19; k++)
	{
		for(int i = 0; i < (1 << k); i++)
			if(!vis[i][k])
			{
				printf("%d\n", k);
				convert(k, i);
				printf("%s\n", ans);
				return 0;
			}
	}
}
