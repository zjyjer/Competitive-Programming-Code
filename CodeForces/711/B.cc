#include <algorithm>
#include <array>
#include <iostream>
#include <map>

const int maxn = 501;
std::array<std::array<int, maxn>, maxn> a;
std::array<long long, maxn> rowsum;
std::array<long long, maxn> colsum;
std::array<long long, 2> diagsum;

int main() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << std::endl;
    return 0;
  }
  int x, y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      if (a[i][j] == 0) {
        std::tie(x, y) = std::make_pair(i, j);
      }
      rowsum[i] += a[i][j];
      colsum[j] += a[i][j];
      if (i == j) {
        diagsum[0] += a[i][j];
      }
      if (i + j == n + 1) {
        diagsum[1] += a[i][j];
      }
    }
  }
  std::map<long long, int> M;
  M[diagsum[0]]++;
  M[diagsum[1]]++;
  for (int i = 1; i <= n; i++) {
    M[rowsum[i]]++;
    M[colsum[i]]++;
  }
  long long ans = -1;
  if (M.size() == 2 && rowsum[x] == M.begin()->first &&
      colsum[y] == M.begin()->first) {
    int cnt = 2;
    if (x == y && diagsum[0] == M.begin()->first) {
      cnt++;
    }
    if (x + y == n + 1 && diagsum[1] == M.begin()->first) {
      cnt++;
    }
    if (M.begin()->second == cnt) {
      ans = M.rbegin()->first - M.begin()->first;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
