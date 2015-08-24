#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 1000005;
const int mod = 1000000007;
std::vector<int> prime;
bool vis[MAXN];

int fastpow(int a, int n) {
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

int inv(int x) {
  return fastpow(x, mod - 2);
}

void init() {
  for (int i = 2; i < MAXN; i ++) {
    if (!vis[i]) {
      prime.push_back(i);
      for (long long j = (long long)i * i; j < MAXN; j += i) {
        vis[j] = 1;
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  init();
  while (T --) {
    int N;
    scanf("%d", &N);
    long long ans = 1;
    for (int i = 0; i < (int)prime.size(); i ++) {
      if (prime[i] > N + 1) {
        break;
      }
      long long tmp = prime[i];
      while (tmp <= N + 1) {
        tmp *= prime[i];
      }
      tmp /= prime[i];
      ans = ans * tmp % mod;
    }
    ans = ans * inv(N + 1) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
