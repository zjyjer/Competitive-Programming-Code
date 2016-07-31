#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <iostream>
using namespace std;

set<long long> S;
char str[12][12];
int pos[12][12], id[12][12];
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};
int ans;

void init()
{
	memset(pos, 0, sizeof(pos));
	int tot = 0;
	for(int i = 1; i <= 10; i++)
		for(int j = 1; j <= 10; j++)
			if((i + j) & 1)
				pos[i][j] = ++tot;
}

void dfs(int i,int j, long long state, int sum)
{
	long long sta = state * 51 + pos[i][j];
	if(S.find(sta) != S.end())
		return;

	S.insert(sta);
	if(sum > ans)
		ans = sum;
	for(int k = 0; k < 4; k++)
	{
		int x = i + dx[k], y = j + dy[k];
		int xx = x + dx[k], yy = y + dy[k];
		if(xx >= 1 && xx <= 10 && yy >= 1 && yy <= 10 && str[x][y] == 'B' && ((state & (1 << id[x][y])) == 0) && str[xx][yy] == '#')
			dfs(xx, yy, state|(1 << id[x][y]), sum + 1);
	}
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		init();
		for(int i = 1; i <= 10; i++)
			scanf("%s", str[i]+1);
		int tot = 0;
		for(int i = 1; i <= 10; i++)
			for(int j = 1; j <= 10; j++)
			{
				if(str[i][j] == 'B')
					id[i][j] = ++tot;
				else id[i][j] = 0;
			}
		ans = 0;
		for(int i = 1; i <= 10; i++)
			for(int j = 1; j <= 10; j++)
			{
				if(str[i][j] != 'W')
					continue;
				str[i][j] = '#';
				S.clear();
				dfs(i, j, 0, 0);
				str[i][j] = 'W';
			}
		printf("%d\n", ans);
	}
	return 0;
}
