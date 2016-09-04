#include <iostream>
#include <string>

const int maxn = 1005;

int main() {
  int n;
  std::cin >> n;
  std::string row[maxn];
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> row[i];
    if (flag)
      continue;
    std::string &str = row[i];
    if (str[0] == 'O' && str[1] == 'O') {
      flag = true;
      str[0] = str[1] = '+';
    } else if (str[3] == 'O' && str[4] == 'O') {
      flag = true;
      str[3] = str[4] = '+';
    }
  }
  std::cout << (flag ? "YES" : "NO") << std::endl;
  if (flag) {
    for (int i = 1; i <= n; i++) {
      std::cout << row[i] << std::endl;
    }
  }
  return 0;
}
