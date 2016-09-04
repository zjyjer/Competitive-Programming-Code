#include <iostream>
#include <vector>
#include <algorithm>

const int mod = 1e6+3;

long long solve(long long n) {
  if (n == 0) {
    return 0;
  }
  return n / 2 + solve(n / 2);
}

int fastpow(int a, long long n) {
  int ret = 1;
  while (n) {
    if (n & 1) {
      ret = 1LL * ret * a % mod;
    }
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ret;
}

int inv(int x) {
  return fastpow(x, mod - 2);
}

int main() {
  unsigned long long n, k;
  std::cin >> n >> k;
  if (n < 64 && (1ULL << n) < k) {
    std::cout << 1 << ' ' << 1 << std::endl;
    return 0;
  }
  std::vector<int>power(mod, 1);
  for (int i = 1; i < mod; i++) {
    power[i] = power[i - 1] * 2 % mod;
  }

  int m = n % (mod - 1);
  int numerator = 1, denominator = 1;
  if (k >= mod) {
    numerator = 0;
  } else {
    for (unsigned int i = 1; i < k; i++) {
      numerator = 1LL * numerator * (mod + power[m] - i) % mod;
    }
  }
  denominator = fastpow(power[m], k - 1);
  int gcd = power[solve(k - 1) % (mod - 1)];
  denominator = 1LL * denominator * inv(gcd) % mod;
  numerator = 1LL * numerator * inv(gcd) % mod;
  std::cout << (denominator - numerator + mod) % mod << ' ' << denominator << std::endl;
  return 0;
}
