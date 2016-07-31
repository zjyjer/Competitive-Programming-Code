#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 105;
int a[maxn], b[maxn], c[maxn], d[maxn];
std::vector<int> g[maxn << 1];
int link[maxn << 1], check[maxn << 1];

void addedge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

bool find(int u) {
  for (size_t i = 0; i < g[u].size(); i++) {
    int &v = g[u][i];
    if (!check[v]) {
      check[v] = 1;
      if (link[v] == -1 || find(link[v])) {
        link[v] = u;
        link[u] = v;
        return true;
      } 
    }
  }
  return false;
}

int hungarian() {
  int ans = 0;
  memset(link, -1, sizeof(link));
  for (int u = 0; u < maxn; u++) {
    if (link[u] == -1) {
      memset(check, 0, sizeof(check));
      if (find(u)) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  int testcase;
  scanf("%d", &testcase);
  while (testcase--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", a + i, b + i);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d %d", c + i, d + i);
    }
    for (int i = 0; i < 2 * maxn; i++) {
      g[i].clear();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i] > d[j] && b[i] >= c[j]) {
          addedge(i, maxn + j);
        }
      }
    }
    printf("%s\n", hungarian() == n ? "Yes" : "No");
  }
  return 0;
}
