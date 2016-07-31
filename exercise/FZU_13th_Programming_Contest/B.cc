#include <iostream>

char g[4][10];
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    for (int i = 0; i < 4; i++) {
      std::cin >> g[i];
    }
    int red, black;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 8; j++) {
        if (g[i][j] == '*') {
          red = i + j;
        } else if (g[i][j] == '.') {
          black = i + j;
        }
      }
    }
    std::cout << ((black - red) % 2 == 0 ? "Black win" : "Red win") << std::endl;
  }
  return 0;
}
