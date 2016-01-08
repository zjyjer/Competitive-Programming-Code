#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n, m;
  set<int> s;
  cin >> n >> m;
  s.clear();
  for (int i = 1; i <= n; i ++) {
    int tmp;
    cin >> tmp;
    while (tmp --) {
      int k;
      cin >> k;
      s.insert(k);
    }
  }
  if ((int)s.size() != m) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
