#include <iostream>
#include <cassert>

const int mod = 1e9+7;
const int maxp = (1000 * 100 + 5) << 1;
const int zero = 1000 * 100;

int score[maxp][2]{{0}, {0}};
int sum[maxp][2]{{0}, {0}};

int main() {
  int a, b, k, t;
  std::cin >> a >> b >> k >> t;
  int cur = 0;
  score[0][1] = 1;
  for (int p = 0; p <= k + 1; p++) {
    sum[zero + p][1] = 1;
  }
  for (int _ = 1; _ <= t; _++) {
    sum[zero + _ * (-k) - 1][cur] = 0;
    for (int p = -k * _; p <= k * _; p++) {
      int maxv = std::min(p + k, k * (_ - 1));
      int minv = std::max(p - k, -k * (_ - 1));
      assert(zero + maxv >= 0);
      assert(zero + minv - 1 >= 0);
      score[zero + p][cur] = (sum[zero + maxv][cur ^ 1] - sum[zero + minv - 1][cur ^ 1] + mod) % mod;
      // printf ("%d <- [%d, %d]  %d - %d = %d\n", p, minv,  maxv, sum[zero + maxv][cur ^ 1], sum[zero + minv - 1][cur ^ 1], score[zero + p][cur]);
      sum[zero + p][cur] = (sum[zero + p - 1][cur] + score[zero + p][cur]) % mod;
    }
    cur ^= 1;
  }
  cur ^= 1;
  int ans = 0;
  for (int p = -k * t; p <= k * t; p++) {
    int minv = std::max(-k * t, b - a + p + 1);
    if (minv > k * t) {
      break;
    }
    // printf ("b get %d point, a should get point between %d ~ %d: %d * %d\n", p, minv, k * t, (sum[zero + k * t][cur] - sum[zero + minv][cur] + mod) % mod, score[zero + p][cur]);
    ans += (1LL * score[zero + p][cur] * ((sum[zero + k * t][cur] - sum[zero + minv - 1][cur] + mod) % mod)) % mod;
    ans %= mod;
  }
  std::cout << ans << std::endl;
  return 0;
}
