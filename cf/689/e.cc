#include <iostream>
#include <cassert>
#include <algorithm>
#include <map>

const int mod = 1000000007;
const int maxn = 200010;
int C[maxn];

int fastpow(int a, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) {
      ret = (1LL * ret * a) % mod;
    }
    a = (1LL * a * a) % mod;
    n >>= 1;
  }
  return ret;
}

int inv(int k) {
  return fastpow(k, mod - 2);
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::map<int, int> events;
  for (int i = 1; i <= n; i++) {
    int l, r;
    std::cin >> l >> r;
    events[l]++; events[r+1]--;
  }

  C[k] = 1;
  for (int i = k + 1; i <= n; i++) {
    C[i] = ((1LL * C[i - 1] * i) % mod * inv(i - k)) % mod;
  }

  long long ans = 0;
  int cnt = 0;
  int pre = events.begin()->first;
  for (auto event : events) {
    int dist = event.first - pre;
    if (cnt >= k) {
      ans += (1LL * C[cnt] * dist) % mod;
      ans %= mod;
    }
    cnt += event.second;
    pre = event.first;
  }

  std::cout << ans << std::endl;
  return 0;
}
