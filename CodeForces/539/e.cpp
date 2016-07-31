#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define All(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> pll;

set<int> S;
map<int, int> M;
vector< int > V1;
vector< pll > V2;
const int maxn = 100010;
int a[maxn], b[maxn];
ll c[maxn * 5];

int lowbit(int s)
{
	return s & -s;
}
void add(int idx, int num) {
	while (idx < 500000) {
		c[idx] += num;
		idx += lowbit(idx);
	}
}
ll getsum(int idx) {
	ll ret = 0;
	while (idx > 0) {
		ret += c[idx];
		idx -= lowbit(idx);
	}
	return ret;
}
void solve()
{
	int n;
	while (cin >> n) {
		V1.clear(); V2.clear();
		V1.pb(0);
		for (int i = 0; i < n; i ++) {
			cin >> a[i] >> b[i];
			V1.pb(a[i]); V1.pb(b[i]);
		}
		sort(V1.begin(), V1.end());
		int len = unique(V1.begin(), V1.end()) - V1.begin();
		for (int i = 1; i < len; i ++) {
			if (V1[i] - V1[i - 1] > 1)
				V2.pb(mp(V1[i - 1] + 1, V1[i] - V1[i - 1] - 1));
			V2.pb(mp(V1[i], 1));
			M[V1[i]] = V2.size() - 1;
		}
		map<ll, int> M2;
		int k = 0;
		for (const auto &v : V2) {
			M2[v.fi] = ++k;
		}
		for (int i = 0; i < n; i ++) {
			int cura = M[a[i]], curb = M[b[i]];
			swap (V2[cura], V2[curb]);
		}
		memset(c, 0, sizeof(c));
		long long ans = 0;
		for (int i = 0; i < V2.size(); i ++) {
			ll val = V2[i].fi;
			int loc = M2[val];
			ans += (ll)(val - getsum(loc) - 1) * V2[i].se;
			add(loc , V2[i].se);
		}
		cout << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
