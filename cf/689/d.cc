#include <iostream>
#include <algorithm>
#include <deque>
#include <cassert>

const int maxn = 200010;
const int INF = ~0u>>1;
int a[maxn], b[maxn];
int maxl[maxn], maxr[maxn], minl[maxn], minr[maxn];

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::deque<int> max, min;
  long long ans = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    while (!max.empty() && a[max.back()] <= a[i]) {
      max.pop_back();
    }
    max.push_back(i);
    while (!min.empty() && b[min.back()] >= b[i]) {
      min.pop_back();
    }
    min.push_back(i);
    while (j <= i && a[max.front()] - b[min.front()] > 0) {
      assert(!max.empty() && !min.empty());
      j++;
      while (!max.empty() && max.front() < j) {
        max.pop_front();
      }
      while (!min.empty() && min.front() < j) {
        min.pop_front();
      }
    }
    if (!max.empty() && !min.empty() && a[max.front()] == b[min.front()]) {
      ans += std::min(max.front(), min.front()) - j + 1;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
