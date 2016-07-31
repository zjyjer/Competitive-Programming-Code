#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 105;
int G[maxn][maxn];
long long dp[maxn][maxn];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(G, 0, sizeof(G));
    for (int i = 0; i < maxn; i++) {
      for (int j = 0; j < maxn; j++) {
        dp[i][j] = (1LL << 63) | 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &G[i][j]);
      }
    }
    int step = (n - 1) << 1;
    dp[0][0] = G[1][1];
    for (int i = 1; i <= step; i++) {
      for (int j = std::min(i, n - 1); j >= std::max(i - n + 1, 0); j--) {
        for (int k = std::min(i, n - 1); k >= std::max(i - n + 1, 0); k--) {
          if (j > 0) {
            dp[j][k] = std::max(dp[j][k], dp[j - 1][k]);
          }
          if (k > 0) {
            dp[j][k] = std::max(dp[j][k], dp[j][k - 1]);
          }
          if (j > 0 && k > 0) {
            dp[j][k] = std::max(dp[j][k], dp[j - 1][k - 1]);
          }
          dp[j][k] += (j == k ? G[j + 1][i - j + 1] : G[j + 1][i - j + 1] + G[k + 1][i - k + 1]); 
        }
      }
    }
    // printf("%lld\n", dp[n - 1][n - 1]);
    printf("%I64d\n", dp[n - 1][n - 1]);
  }
  return 0;
}
