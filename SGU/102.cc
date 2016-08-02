#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int m = sqrt(n + 1);
  int ans = n;
  for (int i = 2; i <= m; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      ans /= i;
      ans *= (i - 1);
    }
  }
  if (n > 1) {
    ans /= n;
    ans *= (n - 1);
  }
  std::cout << ans << std::endl;
  return 0;
}
