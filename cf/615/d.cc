#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200010;
const int mod = 1000000007;
const int mod2 = (mod - 1) * 2;

long long fastpow(int a, long long n) {
  long long ret = 1LL;
  while (n) {
    if (n & 1) {
      ret = ret * a % mod;
    }
    a = (long long)a * a % mod;
    n >>= 1;
  }
  return ret;
}
int cnt[maxn] = {0};
long long cnt2[maxn] = {0LL};

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    int tmp;
    cin >> tmp;
    cnt[tmp] ++;
  }
  long long prod = 1LL;
  for (int i = 0; i < maxn; i ++) {
    prod *= (1 + cnt[i]);
    prod %= mod2;
  }
  long long ans = 1LL;

  for (int i = 0; i < maxn; i ++) {
    cnt2[i] = 1LL * cnt[i] * prod % mod2 / 2;
    long long tmp = fastpow(i, cnt2[i]);
    ans *= tmp;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
