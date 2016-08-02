#include <cstdio>

const int maxn = 1010;
int a[maxn];

int main() {
  int K;
  scanf("%d", &K);
  while (K--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int tmp;
      scanf("%d", &tmp);
      a[i] = tmp % 9;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      ans = (1 + ans) * a[i];
      ans %= 9;
    }
    printf("%d\n", ans == 0? 9 : ans);
  }
  return 0;
}
