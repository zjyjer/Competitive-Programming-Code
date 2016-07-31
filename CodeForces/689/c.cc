#include <iostream>

long long check(long long num) {
  long long ret = 0;
  for (int k = 2; k < num; k++) {
    long long p = 1LL * k * k * k;
    if (num < p) {
      break;
    }
    ret += num / p;
  }
  return ret;
}

int main() {
  long long m;
  std::cin >> m;
  long long low = 0;
  long long high = 1e16;
  while (low < high) {
    long long mid = (low + high) >> 1;
    if (check(mid) < m) {
      low = mid + 1;
    } else if (check(mid) == m) {
      high = mid;
    } else {
      high = mid - 1;
    }
  }
  if (check(low) == m) {
    std::cout << low << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
  return 0;
}
