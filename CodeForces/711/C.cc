#include <iostream>
#include <algorithm>

const int maxn = 101;
const long long int INF = 1e13;
long long dp[maxn][maxn];
long long helper[maxn][3];
long long cost[maxn][maxn];
int c[maxn];

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> cost[i][j];
    }
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = INF;
    }
    helper[i][0] = INF;
    helper[i][1] = INF;
    helper[i][2] = INF;
  }
  if (c[1] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[1][i] = 0;
    }
  } else {
    dp[1][c[1]] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (c[i] != 0) {
      for (int j = k; j >= 1; j--) {
        if (helper[j - 1][2] == c[i]) {
          helper[j][0] = std::min(dp[j][c[i]], helper[j - 1][1]);
        } else {
          helper[j][0] = std::min(dp[j][c[i]], helper[j - 1][0]);
        }
        for (int t = 1; t <= m; t++) {
          dp[j][t] = INF;
        }
        helper[j][1] = INF;
        helper[j][2] = c[i];
        dp[j][c[i]] = helper[j][0];
      }
    } else {
      for (int j = k; j >= 1; j--) {
        long long min1 = INF, min2 = INF;
        long long minindex = -1;
        for (int t = 1; t <= m; t++) {
          if (helper[j - 1][2] == t) {
            dp[j][t] = std::min(dp[j][t], helper[j - 1][1]);
          } else {
            dp[j][t] = std::min(dp[j][t], helper[j - 1][0]);
          }
          dp[j][t] += cost[i][t];
          if (dp[j][t] < min2) {
            min2 = dp[j][t];
          }
          if (dp[j][t] < min1) {
            min2 = min1;
            min1 = dp[j][t];
            minindex = t;
          }
        }
        helper[j][0] = min1;
        helper[j][1] = min2;
        helper[j][2] = minindex;
      }
    }
  }
  long long ans = INF;
  for (int i = 1; i <= m; i++) {
    ans = std::min(ans, dp[k][i]);
  }
  if (ans == INF) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << ans << std::endl;
  }
  return 0;
}
