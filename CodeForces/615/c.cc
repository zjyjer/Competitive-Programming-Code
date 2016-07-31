#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int chs[30], cht[30];

const int maxn = 2150;
int dp[maxn << 1][maxn];
vector<pair<int, int> > V;

int main() {
  string s, t;
  cin >> s >> t;
  int true_len = (int)s.length();
  for (int i = 0; i < (int)s.length(); i ++) {
    chs[s[i] - 'a'] ++;
  }
  for (int i = 0; i < (int)t.length(); i ++) {
    cht[t[i] - 'a'] ++;
  }
  for (int i = 0; i < 26; i ++) {
    if (chs[i] == 0 && cht[i] > 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  string s_rev = s;
  reverse(s_rev.begin(), s_rev.end());
  s.append("&");
  s += s_rev;
  for (int i = (int)s.length() - 1; i >= 0; i --) {
    dp[i][(int)t.length() - 1] = (s[i] == t[(int)t.length() - 1]);
  }
  for (int j = (int)t.length() - 1; j >= 0; j --) {
    dp[(int)s.length() - 1][j] = (t[j] == s[(int)s.length() - 1]);
  }
  for (int i = (int)s.length() - 2; i >= 0; i --) {
    for (int j = (int)t.length() - 2; j >= 0; j --) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      } else {
        dp[i][j] = 0;
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < (int)t.length();) {
    int curmax = 0;
    int l = 0, r = 0;
    for (int i = 0; i < (int)s.length(); i ++) {
      int tmp = dp[i][j];
      if (tmp > curmax) {
        curmax = tmp;
        if (i > true_len) {
          l = 2 * true_len + 2 - (i + 1);
          r = l - tmp + 1;
        } else {
          l = i + 1;
          r = i + tmp - 1;
        } 
      }
    }
    // cout << curmax << ' ' << l << ' ' << r << endl;
    j += curmax;
    V.push_back(make_pair(l, r));
    ans ++;
  }
  cout << ans << endl;
  for (int i = 0; i < (int)V.size(); i ++) {
    cout << V[i].first << ' ' << V[i].second << endl;
  }
  return 0;
}
