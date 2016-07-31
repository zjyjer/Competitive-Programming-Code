#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

#define ll long long
#define pb push_back
vector<pair<int, int> >v;
set<pair<int, int> > s;

int main() {
  int n;
  int a, b;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    s.insert(make_pair(a, b));
  }
  int cur = 0;
  for (auto it : s) {
    if(it.second >= cur)
      cur = it.second;
    else cur = it.first;
  }
  cout << cur << endl;
  return 0;
}
