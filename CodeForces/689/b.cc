#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int maxn = 200005;
int a[maxn], dis[maxn];
std::vector<int> V[maxn];

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    V[i].push_back(i - 1);
    V[i].push_back(i + 1);
    V[i].push_back(a[i]);
    dis[i] = -1;
  }
  dis[1] = 0;
  std::queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int top = Q.front();
    Q.pop();
    for (auto &elem : V[top]) {
      if (dis[elem] == -1) {
        dis[elem] = dis[top] + 1;
        Q.push(elem);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << dis[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
