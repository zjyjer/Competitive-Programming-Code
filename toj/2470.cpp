#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

struct Node {
	int x, y, dis, dir;
	Node() {};
	Node(int a, int b, int c, int d):x(a), y(b), dis(c), dir(d) {};
};

std::queue<Node> Q;
char g[105][105];
bool vis[105][105][4];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m;

bool isvalid (int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != '#';
}

int main() {
	int cas;
	std::cin >> cas;
	while (cas--) {
		std::cin >> n >> m;
		int sx, sy, ex, ey;
		for (int i = 1; i  <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> g[i][j];
				if (g[i][j] == 'S')
					sx = i, sy = j;
				if (g[i][j] == 'T')
					ex = i, ey = j, g[i][j] = '.';
			}
		}
	//	std::cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << std::endl;
		while(!Q.empty()) Q.pop();
		memset(vis, 0, sizeof(vis));
		Node p = Node(sx, sy, 0, 1);
		vis[sx][sy][1] = 1;
		Q.push(p);
		
		bool flag = 1;
		while (!Q.empty()) {
			Node cur = Q.front();
			Q.pop();
			if (cur.x == ex && cur.y == ey) {
				std::cout << cur.dis << std::endl;
				flag = 0;
				break;
			}
			
			//turn left
			Node tmp = Node(cur.x, cur.y, cur.dis + 1, (cur.dir + 1) % 4);	
			if (!vis[tmp.x][tmp.y][tmp.dir]) {
				vis[tmp.x][tmp.y][tmp.dir] = 1;
				Q.push(tmp);
			}

			//turn right
			tmp = Node(cur.x, cur.y, cur.dis + 1, (cur.dir + 3) % 4);
			if (!vis[tmp.x][tmp.y][tmp.dir]) {
				vis[tmp.x][tmp.y][tmp.dir] = 1;
				Q.push(tmp);
			}

			//go straight
			tmp = Node(cur.x + dx[cur.dir], cur.y + dy[cur.dir], cur.dis + 1, cur.dir);
			if (isvalid(tmp.x, tmp.y) && !vis[tmp.x][tmp.y][tmp.dir]) {
				vis[tmp.x][tmp.y][tmp.dir] = 1;
				Q.push(tmp);
			}
		}
		if (flag)
			std::cout << -1 << std::endl;
	}
	return 0;
}
