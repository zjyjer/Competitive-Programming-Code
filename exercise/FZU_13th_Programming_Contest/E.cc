#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

const int maxn = 70000;
int fa[maxn];

int find(int n) {
  if (fa[n] == n) {
    return n;
  } else {
    return fa[n] = find(fa[n]);
  }
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  fa[x] = y;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::vector<std::pair<int, std::pair<int, int> > >V;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int val;
        scanf("%d", &val);
        if (i > j) {
          V.push_back(std::make_pair(val, std::make_pair(i, j)));
        }
      }
    }
    for (int i = 0; i < maxn; i++) {
      fa[i] = i;
    }
    std::sort(V.begin(), V.end());
    int node = n;
    for (size_t i = 0; i < V.size(); i++) {
      int u = V[i].second.first;
      int v = V[i].second.second;
      if (find(u) != find(v)) {
        node--;
        if (node == 1) {
          printf("%d\n", V[i].first);
          break;
        }
        merge(u, v);
      }
    }
  }
  return 0;
}
