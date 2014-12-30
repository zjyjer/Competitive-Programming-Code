#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

typedef std::pair<int, int> P;
#define mp(x,y) std::make_pair(x,y)
#define pb(x) push_back(x);
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans[100];
int sx, sy, ex, ey;
P p1, p2;
int vis[100], g[100][100];
int pre[100];
std::queue<P> Q;

int map (int x, int y) {
	return y * 8 + x + 1;
}

bool isvalid(int n) {
	return n > 0 && n < 7;
}

void buildwall (P s, P e) {
	if (s.first == e.first) {
		for (int i = s.second + 1; i <= e.second; i++) {
			int p = map(s.first, i);
			g[p][p + 1] = 1;
			g[p + 1][p] = 1;
		}
	}
	else {
		for (int i = s.first + 1; i <= e.first; i++) {
		int p = map(i, s.second);
		g[p][p + 8] = 1;
		g[p + 8][p] = 1;
		}
	}
}
int main () {
	while (std::cin >> sx >> sy && sx && sy) {
		std::cin >> ex >> ey;
		memset(vis, 0, sizeof(vis));
		memset(g, 0, sizeof(g));
		memset(ans, 0x3f, sizeof(ans));
		for (int i = 0; i < 3; i++) {
			std::cin >> p1.first >> p1.second >> p2.first >> p2.second;
			if(p1 > p2)
				std::swap(p1, p2);
			buildwall(p1, p2);
		}
		while(!Q.empty()) Q.pop();
		Q.push(mp(sx, sy));
		int p = map(sx, sy);
		vis[p] = 1;
		ans[p] = 0;
		while (!Q.empty()) {
			int tx = Q.front().first;
			int ty = Q.front().second;
			int mapp = map(tx, ty);
			if(tx == ex && ty == ey)
				break;
			for (int i = 0; i < 4; i++) {
				int tempx = tx + dx[i];
				int tempy = ty + dy[i];
				int map1 = map(tempx, tempy);
				if (isvalid(tempx) && isvalid(tempy) && !vis[map1] && !g[map1][mapp]) {
					Q.push(mp(tempx, tempy));
					if (ans[map1] > ans[mapp] + 1) {
						ans[map1] = ans[mapp] + 1;
						pre[map1] = mapp;
					}
					vis[map1] = 1;
				}
			}
			Q.pop();
		}
	//	std::cout << ans[map(ex, ey)] << std::endl;
		int x = map(ex, ey);
		std::vector<char> V;
		V.clear();
		int curx = ex, cury = ey;
		while(curx != sx || cury != sy) {
			int prex = (x - 1) % 8, prey = (x - 1) / 8;
	//		std::cout << curx << ' ' << cury << ' ' << prex << ' ' << prey << std::endl;
			x = pre[x];
			if(curx == prex && cury == prey + 1)
				V.pb('S');
			if(curx == prex && cury == prey - 1)
				V.pb('N');
			if(curx == prex + 1 && cury == prey)
				V.pb('E');
			if(curx == prex - 1 && cury == prey)
				V.pb('W');
			curx = prex, cury = prey;
		}
		for(int i = V.size() - 1; i >= 0; i--)
			std::cout << V[i];
		std::cout << std::endl;
	}
	return 0;
}	
