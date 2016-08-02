#include <iostream>

int calc(int y, int m, int d) {
  if (m <= 2) {
    y--;
    m += 12;
  }
  return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
}
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int m, n;
  std::cin >> m >> n;
  if (m > a[n - 1]) {
    std::cout << "Impossible\n";
  } else {
    std::cout << calc(2001, n, m) << std::endl;
  }
  return 0;
}
