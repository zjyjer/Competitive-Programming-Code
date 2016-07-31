#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>

const int maxn = 505;
int x[maxn], y[maxn];

int main() {
  int n;
  while (std::cin >> n) {
    for (int i = 0; i < n; i++) {
      std::cin >> x[i] >> y[i];
    }
    std::multiset<std::pair<int, int> > S;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        S.insert(std::make_pair((x[i] + x[j]), (y[i] + y[j])));
      }
    }
    long long ans = 0;
    std::multiset<std::pair<int, int> >::iterator iter;
    for (iter = S.begin(); iter != S.end(); ++iter) {
      ans += (S.count(*iter) - 1);
    }
    assert(ans % 2 == 0);
    std::cout << ans / 2 << std::endl;
  }
  return 0;
}
