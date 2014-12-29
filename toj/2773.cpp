#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define debug(x) std::cout << #x << ' ' << x << std::endl;

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};
int map[110][110];
bool vis[110][110];

int n, tmp, sol;
void dfs(int x, int y) {
	sol += map[x][y];
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx <= n && tx >= 1 && ty >= 1 && ty <= n && !vis[tx][ty] && map[tx][ty])
			dfs(tx, ty);
	}
	return;
}
queue<pair<int, int> > Q;
		

void bfs(int x, int y) {
	Q.push(make_pair(x,y));
	vis[x][y] = 1;
	while (!Q.empty()) {
		int xx = Q.front().first;
		int yy = Q.front().second;
		sol += map[x][y];
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = xx + dx[i];
			int ty = yy + dy[i];
			if(tx <= n && tx >= 1 && ty >= 1 && ty <= n && !vis[tx][ty] && map[tx][ty]) {
				Q.push(make_pair(tx,ty));
				vis[tx][ty] = 1;
			}
		}
	}	
}

int main()
{
	int cas;
	std::cin >> cas;
	while (cas--) {
		std::cin >> n;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				std::cin >> map[i][j];
			}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				if (map[i][j] && !vis[i][j]) {
					sol = 0;
//					dfs(i,j);
					bfs(i,j);
					ans = std::max(ans, sol);
				}
		std::cout << ans << std::endl;
	}
	return 0;
}

