#include <iostream>

const int mod = 1000000007;
const int maxn = 5010;
int dp[maxn];
int sum[maxn];

int main() {
  int n, a, b, k;
  std::cin >> n >> a >> b >> k;
  dp[a] = 1;
  for (int i = k; i > 0; i--) {
    sum[0] = 0;
    for (int cur = 1; cur <= n; cur++) {
      sum[cur] = sum[cur - 1] + dp[cur];
      sum[cur] %= mod;
    }
    for (int cur = 1; cur <= n; cur++) {
      if (cur < b) {
        dp[cur] = sum[((cur + b + 1) >> 1) - 1] - dp[cur] + mod;
        dp[cur] %= mod;
      } else if (cur == b) {
        dp[cur] = 0;
      } else {
        dp[cur] = (sum[n] - sum[(cur + b) >> 1] + mod) % mod - dp[cur] + mod;
        dp[cur] %= mod;
      }
    }
  }
  sum[0] = 0;
  for (int cur = 1; cur <= n; cur++) {
    sum[cur] = sum[cur - 1] + dp[cur];
    sum[cur] %= mod;
  }
  std::cout << sum[n] << "\n";
  return 0;
}
