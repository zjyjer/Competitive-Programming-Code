#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const long double eps = 1e-9;
const int maxn = 30;

int equ, var;
long double a[maxn][maxn];
long double b[maxn];
int free_num;

int sign(long double x) {
  if (fabs(x) < eps) {
    return 0;
  }
  return x > eps ? 1 : -1;
}

int Gauss() {
  int i, j, k, row;
  long double maxp, t;
  for (k = 0; k < var; k++) {
    for (maxp = 0, i = k; i < equ; i++)
      if (fabs(a[i][k]) > fabs(maxp) + eps)
        maxp = a[row = i][k];

    if (sign(maxp) == 0) {
      return 0;
    }

    if (row != k) {
      for (j = k; j < var; j++)
        swap(a[k][j], a[row][j]);
      swap(b[k], b[row]);
    }

    for (j = k + 1; j < var; j++) {
      a[k][j] /= maxp;
      for (i = k + 1; i < equ; i++)
        a[i][j] -= a[i][k] * a[k][j];
    }
    b[k] /= maxp;

    for (i = k + 1; i < equ; i++)
      b[i] -= b[k] * a[i][k];
  }

  for (i = equ - 1; i >= 0; i--)
    for (j = i + 1; j < var; j++)
      b[i] -= a[i][j] * b[j];
  return 1;
}

int main() {
  int T;
  std::cin >> T;
  for (int _ = 0; _ < T; _++) {
    int n;
    std::cin >> n;
    equ = var = n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> a[i][j];
      }
      a[i][i] -= 1;
      a[i][n] = 0;
    }
    if (_ % 5 != 0) {
      cout << " ";
    } else if (_ > 0) {
      cout << "\n";
    }
    cout << !Gauss();
  }
  cout << endl;
  return 0;
}
