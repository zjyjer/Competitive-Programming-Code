#include <cstdio>
int main() {
  int n;
  scanf("%d", &n);
  if (n < 9) {
    printf("0\n");
  } else if (n == 9) {
    printf("8\n");
  } else {
    printf("72");
    for (int i = 10; i < n; i++)
      printf("0");
    printf("\n");
  }
  return 0;
}
