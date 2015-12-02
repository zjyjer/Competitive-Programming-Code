#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int m[10], w[10];
  for (int i = 1; i <= 5; i ++) {
    cin >> m[i];
  }
  for (int i = 1; i <= 5; i ++) {
    cin >> w[i];
  }
  int a, b;
  cin >> a >> b;
  long long sum = 0;
  for (int i = 1; i <= 5; i ++) {
    sum += max(150 * i, 500 * i - 2 * m[i] * i - 50 * w[i]); 
  }
  sum += a * 100;
  sum -= b * 50;
  cout << sum << endl;
  return 0;
}
