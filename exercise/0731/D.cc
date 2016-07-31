#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXL = 101;
char str[MAXL];
int dp[MAXL][MAXL];

// [l, r)
int solve(int l, int r) {
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  if (l == r) {
    return dp[l][r] = 0;
  }
  int tmp1 = solve(l + 1, r - 1) + (str[l] == ')') + (str[r-1] == '(');
  int tmp2 = MAXL;
  for (int i = 2; i < r - l; i += 2) {
    tmp2 = std::min(tmp2, solve(l, l + i) + solve(l + i, r));
  }
  return dp[l][r] = std::min(tmp1, tmp2);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int len;
    scanf("%d", &len);
    scanf("%s", str);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, len));
  }
  return 0;
}
