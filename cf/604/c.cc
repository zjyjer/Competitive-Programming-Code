#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;
  string str;
  cin >> n;
  cin >> str;
  int ans = 1;
  char cur = str[0];
  for (int i = 1; i < n; i ++) {
    if (str[i] != cur) {
      ans ++;
      cur = str[i];
    }
  }
  int extra = 0;
  for (int i = 1; i < n; i ++) {
    if (str[i] == str[i - 1]) {
      extra ++;
    }
  }
  if (extra > 2) {
    extra = 2;
  }
  cout << ans + extra << endl;
  return 0;
}
