#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int a, b, c;
  std::vector<int> V;
  std::cin >> a >> b >> c;
  V.push_back(a+b+c);
  V.push_back(a*b*c);
  V.push_back(a*b+a*c);
  V.push_back(a*c+b*c);
  std::cout << *std::max_element(V.begin(), V.end()) << std::endl;
  return 0;
}
