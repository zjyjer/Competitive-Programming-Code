#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100010;
int dp[maxn] = {0};
int cnt[maxn] = {0};
vector<int> V[maxn];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i ++) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    cnt[u] ++;
    cnt[v] ++;
    V[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i ++) {
    dp[i] = 1;
    for (int j = 0; j < (int)V[i].size(); j ++) {
      int tmp = V[i][j];
      dp[i] = max(dp[i], dp[tmp] + 1);
    }
    if (1LL * dp[i] * cnt[i] > ans) {
      // cout << i << ' ' << dp[i] << ' ' << V[i].size() << endl;
      ans = 1LL * dp[i] * cnt[i];
    }
  }
  cout << ans << endl;
  return 0;
}
