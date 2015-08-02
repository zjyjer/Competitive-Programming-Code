#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int> > V;
std::vector<std::pair<int, int> > OP;
int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int tmp;
    std::cin >> tmp;
    V.push_back(std::make_pair(tmp, i));
  }
  bool flag = false;
  for (int i = 0; i < k; i++) {
    std::sort(V.begin(), V.end());
    auto &max = *V.rbegin();
    auto &min = *V.begin();
    auto diff = max.first - min.first;
    if (diff <= 1) {
      std::cout << diff << ' ' << i << "\n";
      flag = true;
      break;
    }
    max.first--;
    min.first++;
    OP.push_back(std::make_pair(max.second, min.second));
  }
  if  (!flag) {
    std::sort(V.begin(), V.end());
    auto &max = *V.rbegin();
    auto &min = *V.begin();
    auto diff = max.first - min.first;
    std::cout << diff << ' ' << k << std::endl;
  }
  for (auto it:OP) {
    std::cout << it.first << ' ' << it.second << "\n";
  }
  return 0;
}
