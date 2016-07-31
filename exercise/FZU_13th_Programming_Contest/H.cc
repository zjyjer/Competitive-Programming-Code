#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 100005;
const int mod = 1000000007;
int a[maxn], b[maxn], c[maxn];
long long dp[maxn];

int lowbit(int x) {
  return x & (-x);
}

long long bit[maxn];

void add(int a, int delta) {
  while (a < maxn) {
    bit[a] += delta;
    if (bit[a] >= mod) {
      bit[a] -= mod;
    }
    a += lowbit(a);
  }
}

long long sum (int a) {
  long long ret = 0;
  while (a > 0) {
    ret += bit[a];
    if (ret >= mod) {
      ret -= mod;
    }
    a -= lowbit(a);
  }
  return ret;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      b[i] = a[i];
    }
    std::sort(a, a + n);
    int size = std::unique(a, a + n) - a;
    for (int i = 0; i < n; i++) {
      c[i] = std::upper_bound(a, a + size, b[i]) - a;
    }

    // dp[j] = \sum_{i < j, a_i < a_j}dp[i] + 1
    for (int i = 0; i < n; i++) {
      dp[i] = sum(c[i] - 1) + 1;
      add(c[i], dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += dp[i];
      if (ans >= mod) {
        ans -= mod;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
