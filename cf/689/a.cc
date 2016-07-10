#include <algorithm>
#include <iostream>
#include <string>

bool used[10] = {0};

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  for (char &ch : s) {
    used[ch - '0'] = true;
  }
  if ((!used[1] && !used[2] && !used[3]) ||
      (!used[1] && !used[4] && !used[7] && !used[0]) ||
      (!used[7] && !used[0] && !used[9]) ||
      (!used[3] && !used[6] && !used[9] && !used[0])) {
    std::cout << "NO" << std::endl;
  } else {
    std::cout << "YES" << std::endl;
  }
  return 0;
}
