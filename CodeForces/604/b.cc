#include <iostream>

using namespace std;

const int maxn = 100010;
int s[maxn];
int n, k;

bool check(long long v) {
  int sum = 0;
  int l = 1;
  int r = n;
  while (r > l) {
    if (v >= s[l] + s[r]) {
      l ++;
    }
      sum ++;
      r --;
  }
  if (l == r) {
  sum ++;
  }
  return sum <= k;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i ++) {
    cin >> s[i];
  }
  long long hi = 100000000000LL;
  long long lo = s[n] * 1LL;
  while (lo < hi) {
    long long mid = (hi + lo) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
  return 0;
}
