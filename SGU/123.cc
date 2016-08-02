#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n < 3) {
    std::cout << n << std::endl;
    return 0;
  }
  int f1 = 1, f2 = 1;
  int s = 2;
  for (int i = 3; i <= n; i++) {
    int f = f1 + f2;
    s += f;
    f1 = f2;
    f2 = f;
  }
  std::cout << s << std::endl;
  return 0;
}
