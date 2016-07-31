#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, sr, dn;
int a[110000], s[110000], d[210000], qr[110000][3];

int main() {
  while (scanf("%d", &n) == 1) {
    dn = n;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memcpy(d, a, sizeof(a[0]) * n);
    memcpy(s, a, sizeof(a[0]) * n);
    sr = (int)sqrt(n + 0.5) * 2;
    for (int i = 0; i < n; i += sr) {
      int j = min(n, i + sr);
      sort(s + i, s + j);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      char c[2];
      scanf("%s", c);
      if (c[0] == '2') {
        scanf("%d %d %d", qr[i], qr[i] + 1, qr[i] + 2);
        --qr[i][0];
        --qr[i][1];
      } else {
        scanf("%d %d", qr[i], qr[i] + 1);
        qr[i][2] = -1;
        --qr[i][0];
        d[dn++] = qr[i][1];
      }
    }
    sort(d, d + dn);
    dn = unique(d, d + dn) - d;
    for (int i = 0; i < m; ++i) {
      if (qr[i][2] == -1) {
        int &p = qr[i][0], &v = qr[i][1];
        int beg = p / sr * sr;
        int end = min(beg + sr, n);
        *lower_bound(s + beg, s + end, a[p]) = v;
        sort(s + beg, s + end);
        a[p] = v;
      } else {
        int &l = qr[i][0], &r = qr[i][1], &k = qr[i][2];
        int lf = 0, rt = dn - 1;
        while (lf <= rt) {
          int md = (lf + rt) >> 1;
          int v = d[md];
          int cnt = 0;
          for (int beg = l / sr * sr; beg <= r; beg += sr) {
            int end = min(beg + sr, n);
            if (l <= beg && r >= end - 1) {
              cnt += lower_bound(s + beg, s + end, v) - (s + beg);
            } else {
              for (int p = max(beg, l); p < end && p <= r; ++p) if (a[p] < v) ++cnt;
            }
          }
          cnt >= k ? (rt = md - 1) : (lf = md + 1);
        }
        printf("%d\n", d[rt]);
      }
    }
  }
  return 0;
}
