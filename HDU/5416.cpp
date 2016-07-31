#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

const int MAXS = 1 << 18;
const int MAXN = 100005;
std::vector<std::pair<int, int> > V[MAXN];
int cnt[MAXS], dp[MAXN];

void dfs(int cur, int fa, int val) {
  dp[cur] = dp[fa] ^ val;
  cnt[dp[cur]] ++;
  for (int i = 0; i < (int)V[cur].size(); i ++) {
    int to = V[cur][i].first;
    int w = V[cur][i].second;
    if (to != fa) {
      dfs(to, cur, w);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    int x, y, z;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i < MAXN; i ++) {
      V[i].clear();
    }
    for (int i = 1; i < n; i ++) {
      scanf("%d %d %d", &x, &y, &z);
      V[x].push_back(std::make_pair(y, z));
      V[y].push_back(std::make_pair(x, z));
    }
    dfs(1, 0, 0);
    int Q, s;
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
      scanf("%d", &s);
      long long ans = 0;
      for (int j = 0; j < MAXS; j ++) {
        ans += (long long)cnt[j] * cnt[s ^ j];
        if (!s) {
          ans += cnt[j];
        }
      }
      ans >>= 1;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
