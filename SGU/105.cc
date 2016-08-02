#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << n / 3 * 2 + (n % 3) - (n % 3 > 0) << std::endl;
  return 0;
}
