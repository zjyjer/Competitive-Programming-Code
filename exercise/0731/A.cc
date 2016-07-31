#include <cctype>
#include <iostream>
#include <string>

using pii = std::pair<int, int>;

pii Union(pii a, pii b) {
  return pii(std::max(a.first, b.first), a.second + b.second);
}

pii Merge(pii a, pii b) {
  return pii(std::min(a.first + b.second, a.second + b.first),
             a.second + b.second);
}

std::string str;

bool isAtom(int l, int r) {
  for (int i = l; i < r; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

// [l, r)
pii parse(int l, int r) {
  if (isAtom(l, r)) {
    return pii(1, 1);
  }
  int cnt = 0;
  pii p(0, 0);
  for (int i = l; i < r; i++) {
    if (cnt == 0) {
      if (str[i] == 'J') {
        p = Merge(parse(l + 1, i - 1), parse(i + 2, r - 1));
      }
      if (str[i] == 'U') {
        p = Union(parse(l + 1, i - 1), parse(i + 2, r - 1));
      }
    }
    if (str[i] == '(') {
      cnt++;
    }
    if (str[i] == ')') {
      cnt--;
    }
    if (isdigit(str[i])) {
      while (isdigit(str[i + 1])) {
        i++;
      }
    }
  }
  return p;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n >> str;
    std::cout << parse(0, str.length()).first << std::endl;
  }
  return 0;
}
