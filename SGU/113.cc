#include <iostream>
#include <cmath>
#include <cstdlib>

const int MAXP = 35000;
bool vis[MAXP] = {0};
int cnt = 0;
int prime[MAXP];

void init() {
  for (int i = 2; i < MAXP; i++) {
    if (!vis[i]) {
      prime[cnt++] = i;
      for (int j = i * i; j < MAXP; j += i) {
        vis[j] = 1;
      }
    }
  }
}

int main() {
  init();
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int m = sqrt(1 + n);
    int step = 0;
    while (prime[step] <= m) {
      if (n % prime[step] == 0) {
        n /= prime[step];
        break;
      }
      step++;
    }
    if (prime[step] > m) {
      std::cout << "No\n";
      continue;
    }
    m = sqrt(1 + n);
    bool flag = true;
    step = 0;
    while (prime[step] <= m) {
      if (n % prime[step] == 0) {
        flag = false;
        break;
      }
      step++;
    }
    std::cout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}
