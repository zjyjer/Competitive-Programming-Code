#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string str1 = "Kevin";
const string str2 = "Nicky";

int f(int t) {
  if (t % 2 == 1 && t >= 5) {
    return 0;
  } else if (t % 2 == 1 && t < 5) {
    return 1;
  } else if (t % 2 == 0 && t <= 4) {
    return t - 2;
  } else {
    if (f(t / 2) != 1) {
      return 1;
    } else {
      return 2;
    }
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  k %= 2;
  int sg = 0;
  for (int i = 1; i <= n; i ++) {
    int tmp;
    cin >> tmp;
    if (k == 0) {
      if (tmp >= 3) {
        sg ^= (tmp + 1) % 2;
      } else  {
        sg ^= tmp;
      } 
    } else if (k == 1) {
      sg ^= f(tmp);
    }
  }
  if (sg != 0) {
    cout << str1 << endl;
  } else {
    cout << str2 << endl;
  }
  return 0;
}
