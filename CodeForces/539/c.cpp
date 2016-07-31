#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define All(x) (x).begin(),(x).end()

int dirx[4] = {0,0,1,-1};
int diry[4] = {1,-1,0,0};
typedef pair<int, int> pii;
typedef long long ll;

set<int> S;
map<int, int> M;

int G[600][600];
char ch[600][600];
void solve() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			cin >> ch[i] + 1;
		int sx, sy, dx, dy;
		cin >> sx >> sy >> dx >> dy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (ch[i][j] == 'X')
					G[i][j] = 1;
				else
					G[i][j] = 0;
			}
		}
		queue<pii> Q;
		Q.push(mp(sx, sy));
		if (sx != dx || sy != dy)
			G[sx][sy] ++;
		while (!Q.empty()) {
			pii p = Q.front();
			Q.pop();
			int xx = p.fi, yy = p.se;
			if (xx == dx && yy == dy && G[dx][dy] == 2) {
				cout << "YES" << endl;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int tmpx = xx + dirx[i];
				int tmpy = yy + diry[i];
				if (tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m && G[tmpx][tmpy] == 0) {
					G[tmpx][tmpy]++;
					Q.push(mp(tmpx, tmpy));
				}
				else if (tmpx == dx && tmpy == dy && G[tmpx][tmpy] == 1) {
					G[tmpx][tmpy]++;
					Q.push(mp(tmpx, tmpy));
				}
			}
		}
		cout << "NO" << endl;
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
