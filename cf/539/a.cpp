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

set<int> S;
map<int, int> M;

void solve() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int n1 = s1[i] - '0' ? s1[i] : s1[i] + 10;
		int n2 = s2[i] - '0' ? s2[i] : s2[i] + 10;
		if (n1 < n2)
			swap(n1, n2);
		ans += min(abs(n1 - n2), abs(10 - n1 + n2));
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
		solve();
	return 0;
}
