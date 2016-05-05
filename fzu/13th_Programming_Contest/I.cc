#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxm = 50005;
const int maxv = 100005;
const int maxn = maxv * 20;
int lson[maxn], rson[maxn], cnt[maxn];
int root[maxv], nodecnt = 0;

std::vector<std::pair<int, int> >V[maxm];
int f[maxm], w[maxm];
int depth[maxm];
int dp[maxm][20];

int build(int l, int r) {
  int cur = nodecnt++;
  cnt[cur] = 0; 
  if (l != r) {
    int mid = (l + r) >> 1;
    lson[cur] = build(l, mid);
    rson[cur] = build(mid + 1, r);
  }
  return cur;
}

int update(int pre, int val, int l, int r) {
  int cur = nodecnt++;
  cnt[cur] = cnt[pre] + 1;
  if (l != r) {
    int mid = (l + r) >> 1;
    if (val <= mid) {
      lson[cur] = update(lson[pre], val, l, mid);
      rson[cur] = rson[pre];
    } else {
      lson[cur] = lson[pre];
      rson[cur] = update(rson[pre], val, mid + 1, r);
    }
  }
  return cur;
}

int query(int roota, int rootb, int rootlca, int l, int r, int k) {
  if (l == r) {
    return l;
  }
  int lnum = cnt[lson[roota]] + cnt[lson[rootb]] - 2 * cnt[lson[rootlca]];
  int mid = (l + r) >> 1;
  if (lnum >= k) {
    return query(lson[roota], lson[rootb], lson[rootlca], l, mid, k);
  } else {
    return query(rson[roota], rson[rootb], rson[rootlca], mid + 1, r, k - lnum);
  }
}

void dfs(int u, int fa) {
  depth[u] = depth[fa] + 1;
  for (size_t i = 0; i < V[u].size(); i++) {
    int v = V[u][i].first;
    if (v == fa) {
      f[u] = fa;
      w[u] = V[u][i].second;
    } else {
      dfs(v, u);
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    std::swap(u, v);
  }
  for (int i = 19; i >= 0; i--) {
    if (depth[dp[u][i]] >= depth[v]) {
      u = dp[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  }
  return dp[u][0];
}

int main() {
  int n, q;
  while (scanf("%d %d", &n, &q) == 2) {
    for (int i = 0; i < maxm; i++) {
      V[i].clear();
    }
    nodecnt = 0;
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      V[u].push_back(std::make_pair(v, w));
      V[v].push_back(std::make_pair(u, w));
    }
    root[1] = build(0, 100000); 
    depth[0] = 0;
    dfs(1, 0);
    dp[1][0] = 0;
    for (int j = 2; j <= n; j++) {
      dp[j][0] = f[j];
    }
    for (int level = 1; level < 20; level++) {
      for (int i = 2; i <= n; i++) {
        dp[i][level] = dp[dp[i][level-1]][level - 1];
      }
    }
    for (int i = 2; i <= n; i++) {
      root[i] = update(root[f[i]], w[i], 0, 100000);
    }
    for (int i = 1; i <= q; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      int ancestor = lca(u, v);
      int num = cnt[root[u]] + cnt[root[v]] - 2 * cnt[root[ancestor]];
      printf("%d\n", query(root[u], root[v], root[ancestor], 0, 100000, (num + 1) / 2));
    }
  }
  return 0;
}
