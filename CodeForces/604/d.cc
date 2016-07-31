#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int powmod(int a, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) {
      ret = (long long)ret * a % mod;
    }
    a = (long long)a * a % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  int p, k;
  cin >> p >> k;
  if (k == 0) {
    cout << powmod(p, p - 1) << endl;
  } else if (k == 1) {
    cout << powmod(p, p) << endl;
  } else {
    int m = 1;
    int cur = k;
    while (cur % p != 1) {
      cur = (long long)cur * k % p;
      m ++;
    }
    cout << powmod(p, (p - 1) / m) << endl;
  }
  return 0;
}
