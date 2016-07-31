#include <iostream>

const long long mod = 1000000007;
long long f[100005];

long long fastpow(long long n, long long a) {
  long long ret = 1;
  while (a) {
    if (a & 1) {
      ret = (long long)ret * n % mod;
    }
    n = (long long)n * n % mod;
    a >>= 1;
  }
  return ret;
}

long long inv(int x) {
  return fastpow(x, mod - 2);
}

void init() {
  f[0] = 1;
  for (int i = 1; i <= 100000; i ++) {
    f[i] = f[i - 1] * i % mod;
  }
}

long long binom(int n, int m) {
  if (n < m)
    return 0;
  return f[n] * inv(f[m]) % mod * inv(f[n - m]) % mod;
}

int main() {
  init();
  int cas;
  std::cin >> cas;
  for (int t = 1; t <= cas; t ++) {
    std::cout << "Case #" << t << ": ";
    long long n, m, k;
    std::cin >> n >> m >> k;
    long long kk = n / 2;
    if (k >= 4) {
      std::cout << "0\n";
      continue;
    }
    if (m == 3) {
      if (k < 2) {
        std::cout << "0\n";
        continue;
      }
      long long tmp = n * kk % mod * kk % mod;
      long long m3 = (tmp - binom(n, 3) + mod) % mod * inv(2) % mod;
      long long m2 = (binom(n, 3) - m3 + mod) % mod;
      if (k == 2) {
        std::cout << m2 << "\n";
        continue;
      }
      if (k == 3) {
        std::cout << m3 << "\n";
        continue;
      }
    }
    if (m == 4) {
      if (k != 2) {
        std::cout << "0\n";
        continue;
      }
      std::cout << binom(n, 4) << "\n";
      continue;
    }
    if (k == 3) {
      std::cout << "0\n";
      continue;
    } 
    long long m2 = (n * binom(kk, m - 1) + n * binom(kk + 1, m - 1)) % mod;
    long long m1 = ((kk * n % mod * binom(kk, m - 2) % mod - 2 * m2 + n * binom(kk, m - 1)) % mod + mod) % mod;
    long long m0 = ((binom(n, m) - m1 - m2) % mod + mod) % mod;
    if (k == 0) {
      std::cout << m0 << "\n";
    }
    if (k == 1) {
      std::cout << m1 << "\n";
    }
    if (k == 2) {
      std::cout << m2 << "\n";
    }
  }
  return 0;
}
