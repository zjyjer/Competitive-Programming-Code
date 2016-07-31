#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using pii = std::pair<int, int>;

const int maxn = 500010;
int n, s, m;
std::vector<std::pair<int, int>> V[maxn];
std::vector<int> ans;
bool vis[maxn];

inline int fa(int i) { return i >> 1; }

inline int lson(int i) { return i << 1; }

inline int rson(int i) { return (i << 1) + 1; }

inline int check(int i) { return i > 0 && i <= n; }

struct cmp {
  bool operator()(pii a, pii b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second > b.second;
  }
};

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::cin >> n >> s >> m;
    memset(vis, 0, sizeof(vis));
    ans.clear();
    for (int i = 1; i <= n; i++) {
      V[i].clear();
      if (check(fa(i))) {
        V[i].push_back(std::make_pair((i - fa(i)) % m, fa(i)));
      }
      if (check(lson(i))) {
        V[i].push_back(std::make_pair((lson(i) - i) % m, lson(i)));
      }
      if (check(rson(i))) {
        V[i].push_back(std::make_pair((rson(i) - i) % m, rson(i)));
      }
    }
    std::priority_queue<pii, std::vector<pii>, cmp> Q;
    vis[s] = 1;
    Q.push(std::make_pair(0, s));
    while (!Q.empty()) {
      auto p = Q.top();
      Q.pop();
      ans.push_back(p.second);
      for (size_t i = 0; i < V[p.second].size(); i++) {
        auto extend = V[p.second][i];
        if (!vis[extend.second]) {
          vis[extend.second] = 1;
          Q.push(extend);
        }
      }
    }
    std::cout << ans[0];
    for (size_t i = 1; i < ans.size(); i++) {
      std::cout << ' ' << ans[i];
    }
    std::cout << std::endl;
  }
  return 0;
}
