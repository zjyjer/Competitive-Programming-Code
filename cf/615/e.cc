#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 0 << ' ' << 0 << endl;
    return 0;
  }  
  long long lo = 0, hi = 1e9;
  long long &nums = lo;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (3LL * mid * (mid + 1) < n) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  long long s = 3LL * nums * (nums + 1) + 1;
  long long sx = 2 * nums + 1;
  long long sy = 0 + 2;
  long long delta = n - s;
  if (delta < nums) {
    cout << sx - delta << ' ' << sy + 2 * delta << endl;
    return 0;
  }
  delta -= nums;
  sx -= nums;
  sy += 2 * nums;
  nums ++;
  if (delta < nums) {
    cout << sx - 2 * delta << ' ' << sy << endl;
    return 0;
  }
  delta -= nums;
  sx -= 2 * nums;
  if (delta < nums) {
    cout << sx - delta << ' ' << sy - 2 * delta << endl;
    return 0;
  }
  delta -= nums;
  sx -= nums;
  sy -= 2 * nums;
  if (delta < nums) {
    cout << sx + delta << ' ' << sy - 2 * delta << endl;
    return 0;
  }
  delta -= nums;
  sx += nums;
  sy -= 2 * nums;
  if (delta < nums) {
    cout << sx + 2 * delta << ' ' << sy << endl;
    return 0;
  }
  delta -= nums;
  sx += 2 * nums;
  cout << sx + delta << ' ' << sy + 2 * delta << endl;
  return 0;
}
