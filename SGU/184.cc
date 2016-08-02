#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, c, a1, b1, c1, d1;
  while (cin >> a >> b >> c >> a1 >> b1 >> c1) {
    cout << min(min(a / a1, b / b1), c / c1) << endl;
  }
  return 0;
}
