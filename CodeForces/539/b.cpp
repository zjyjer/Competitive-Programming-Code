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

int s[1010];

void solve() {
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	int sum = 0;
	int low = 0;
	for (int i = 0; i < k; i++) {
		cin >> s[i];
		sum += s[i];
		if (s[i] < y)
			low++;
	}	
	k = n - k;
	bool flag = false;
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int cur = sum + i + y * (k - i);
		int l = low + i;
//		cout << i << ' ' << cur << ' ' << l << ' ' << (n >> 1) << endl;
		if (cur <= x && l <= (n >> 1)) {
			flag = true;
			ans = i;
		}
		if (flag)
			break;
	}
	if (!flag)
		cout << -1 << endl;
	else {
		for (int i = 0; i < ans; i++)
			cout << 1 << ' ';
		for (int i = ans; i < k; i++)
			cout << y << ' ';
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
		solve();
	return 0;
}
