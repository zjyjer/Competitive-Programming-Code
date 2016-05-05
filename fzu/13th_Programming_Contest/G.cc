#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int MAXN = 2e9;
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

const int MAXP = 100005;
bool vis[MAXP];

int main() {
  int sx, sy, tx, ty;
  int n, x, y, z;
  while (scanf("%d %d %d %d", &sx, &sy, &tx, &ty) == 4) {
    scanf("%d", &n);
    std::vector<std::pair<int, int> > V;
    while (n--) {
      scanf("%d %d %d", &x, &y, &z);
      for (int i = y; i <= z; i++) {
        V.push_back(std::make_pair(x, i));
      }
    }
    sort(V.begin(), V.end());
    int size = unique(V.begin(), V.end()) - V.begin();
    V.resize(size);
    std::queue<std::pair<std::pair<int, int>, int> >Q;
    memset(vis, 0, sizeof(vis));
    std::pair<int, int> sp = std::make_pair(sx, sy);
    Q.push(std::make_pair(sp, 0));
    int k = std::lower_bound(V.begin(), V.end(), sp) - V.begin();
    vis[k] = true;
    bool flag = false;
    while (!Q.empty()) {
      std::pair<std::pair<int, int>, int> p = Q.front();
      Q.pop();
      if (p.first == std::make_pair(tx, ty)) {
        printf("%d\n", p.second);
        flag = true;
        break;
      }
      for (int i = 0; i < 8; i++) {
        int nx = p.first.first + dx[i];
        int ny = p.first.second + dy[i];    
        if (nx >= 1 && nx <= MAXN && ny >= 1 && ny <= MAXN) {
          std::pair<int, int> np = std::make_pair(nx, ny);
          int k = std::lower_bound(V.begin(), V.end(), np) - V.begin();
          if (V[k] == np && vis[k] == false) {
            vis[k] = true;
            Q.push(std::make_pair(np, p.second + 1));
          }
        }
      } 
    }
    if (!flag) {
      printf("-1\n");
    }
  }
  return 0;
}
