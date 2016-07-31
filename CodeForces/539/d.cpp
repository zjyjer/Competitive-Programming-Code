#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define All(x) (x).begin(),(x).end()
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

set<int> S;
map<int, int> M;

ld dp[110][110][110];
ld a1,a2,a3;
int r, s, p;

long double sol(int x, int y, int z) {
	if (x > r || y > s || z > p)
		return 0.0;
	else
		return dp[x][y][z] ;
}

int sqr(int x) {
	return x * x;
}
void solve() {
	while (cin >> r >> s >> p) {
		memset(dp, 0, sizeof(dp));
		dp[r][s][p] = 1.0;
		a1 = a2 = a3 = 0.0;
		for (int i = r; i >= 0; i--) {
			for (int j = s; j >= 0; j--) {
				for (int k = p; k >= 0; k--) {
					if (i + j + k == 0 || i + j + k == r + s + p)
						continue;
					int sum = i + j + k + 1;
					if (i+j != 0)
						dp[i][j][k] += sol(i, j, k + 1) * j * (k + 1) * 2 / (sqr(sum) - sqr(i) - sqr(j) - sqr(k + 1));
					if (i+k != 0)
						dp[i][j][k] += sol(i, j + 1, k) * i * (j + 1) * 2 / (sqr(sum) - sqr(i) - sqr(j + 1) - sqr(k));
					if (j+k != 0)
						dp[i][j][k] += sol(i + 1, j, k) * k * (i + 1) * 2 / (sqr(sum) - sqr(i + 1) - sqr(j) - sqr(k));
						
					if (i+j == 0)
						a3 += dp[i][j][k];
					if (i+k == 0)
						a2 += dp[i][j][k];
					if (j+k == 0)
						a1 += dp[i][j][k];
				}
			}
		}
		long double temp = a1 + a2 + a3;
		cout << a1 / temp << ' ' << a2 / temp << ' ' << a3 / temp << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);
	solve();
	return 0;
}
