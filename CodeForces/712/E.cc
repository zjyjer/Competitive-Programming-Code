#include <algorithm>
#include <iomanip>
#include <iostream>

const int maxn = 100010;
int a[maxn], b[maxn];
std::pair<double, double> value[maxn << 2];
using Node = std::pair<double, double>;

Node merge(Node childL, Node childR) {
  double l1, r1, l2, r2;
  std::tie(l1, r1) = childL;
  std::tie(l2, r2) = childR;
  double l = l1 * l2 / (1 + r1 * (l2 - 1));
  double r = r2 + (r1 * l2 * (1 - r2)) / (1 + r1 * (l2 - 1));
  return std::make_pair(l, r);
}

void update(int o, int l, int r, int begin, int end, double value) {
  if (begin > r || end < l) {
    return;
  }
  if (begin == l && end == r) {
    ::value[o] = std::make_pair(value, value);
    return;
  }
  int m = (l + r) >> 1;
  update(o * 2, l, m, begin, end, value);
  update(o * 2 + 1, m + 1, r, begin, end, value);
  ::value[o] = merge(::value[o * 2], ::value[o * 2 + 1]);
}

Node query(int o, int l, int r, int begin, int end) {
  if (begin > r || end < l) {
    return std::make_pair(1.0, 0.0);
  }
  if (l >= begin && r <= end) {
    return value[o];
  }
  int m = (l + r) >> 1;
  auto resultL = query(o * 2, l, m, begin, end);
  auto resultR = query(o * 2 + 1, m + 1, r, begin, end);
  return merge(resultL, resultR);
}

int main() {
  int n, q;
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    update(1, 1, n, i, i, a[i] * 1.0 / b[i]);
  }
  for (int i = 0; i < q; i++) {
    int oper;
    std::cin >> oper;
    if (oper == 1) {
      int index, a, b;
      std::cin >> index >> a >> b;
      update(1, 1, n, index, index, a * 1.0 / b);
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << std::fixed << std::setprecision(9) << query(1, 1, n, l, r).first << std::endl;
    }
  }
  return 0;
}
