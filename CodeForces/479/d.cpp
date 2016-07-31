#include <iostream>
#include <algorithm>
#include <set>

int main() {
  int n, l, x, y;
  std::cin >> n >> l >> x >> y;
  std::set<int> S;
  int tmp;
  for (int i = 0; i < n; i ++) {
    std::cin >> tmp;
    S.insert(tmp);
  }
  bool flagx = false, flagy = false;
  for (auto it : S) {
    if (S.count(it + x)) {
      flagx = true;
    }
    if (S.count(it + y)) {
      flagy = true;
    }
  }
  if (flagx && flagy) {
    std::cout << 0 << "\n";
    return 0;
  } else if (flagx != flagy) {
    std::cout << 1 << "\n";
    if (!flagx) {
      std::cout << x << "\n";
    } else {
      std::cout << y << "\n";
    }
    return 0;
  }
  for (auto it : S) {
    if (it + x < l && !S.count(it + x) && (S.count(it + x - y) || S.count(it + x + y))) {
      std::cout << 1 << "\n";
      std::cout << it + x << "\n";
      return 0;
    }
    if (it - x > 0 && !S.count(it - x) && (S.count(it - x - y) || S.count(it - x + y))) {
      std::cout << 1 << "\n";
      std::cout << it - x << "\n";
      return 0;
    }
    if (it + y < l && !S.count(it + y) && (S.count(it + y - x) || S.count(it + y + x))) {
      std::cout << 1 << "\n";
      std::cout << it + y << "\n";
      return 0;
    }
    if (it - y > 0 && !S.count(it - y) && (S.count(it - y - x) || S.count(it - y + x))) {
      std::cout << 1 << "\n";
      std::cout << it - y << "\n";
      return 0;
    }
  }
  std::cout << 2 << "\n";
  std::cout << x << ' ' << y << "\n";
  return 0;
}
