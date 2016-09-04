#include <algorithm>
#include <iostream>
#include <vector>

const int maxn = 200001;
const int mod = 1e9 + 7;
std::vector<int> V[maxn];
std::vector<int> power2(maxn, 1);
std::vector<int> vis(maxn, 0);
std::vector<int> pa(maxn, 0);

void dfs(int cur, int fa, int &cnt, int &num) {
  vis[cur] = cnt++;
  pa[cur] = fa;
  for (auto s : V[cur]) {
    if (s == fa) {
      continue;
    }
    if (vis[s]) {
      if (vis[s] <= vis[cur]) {
        continue;
      }
      while (s != cur) {
        num++;
        s = pa[s];
      }
    } else {
      dfs(s, cur, cnt, num);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int tmp;
    std::cin >> tmp;
    V[i].push_back(tmp);
    V[tmp].push_back(i);
    power2[i] = (power2[i - 1] * 2LL) % mod;
  }
  long long ans = 1LL;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int num = 1;
      int cnt = 1;
      dfs(i, 0, cnt, num);
      // std::cout << cnt << ' ' << num << std::endl;
      ans *= (power2[cnt - 1] - power2[cnt - num] + mod) % mod;
      ans %= mod;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
