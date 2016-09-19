#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class SubtreeSum {
    public:
    std::vector<int> V[100];
    std::vector<long long> cnt;
    std::vector<int> vis;
    const int mod = 1e9 + 7;
    int getSum(vector<int> p, vector<int> x) {
      for (size_t i = 0; i < p.size(); i++) {
        V[i + 1].push_back(p[i]);
        V[p[i]].push_back(i + 1);
      }
      cnt.resize(x.size());
      vis.resize(x.size());
      fill(cnt.begin(), cnt.end(), 0);
      dfs(0, -1);
      long long num = accumulate(cnt.begin(), cnt.end(), 0);
      num %= mod;
      long long ans = 0;
      for (int k = 0; k < 32; k++) {
        for (size_t i = 0; i < x.size(); i++) {
          V[i].clear();
        }
        for (size_t i = 0; i < p.size(); i++) {
          if ((x[i + 1] & (1 << k)) == 0 && (x[p[i]] & (1 << k)) == 0) {
            V[i + 1].push_back(p[i]);
            V[p[i]].push_back(i + 1);
          }
        }
        fill(vis.begin(), vis.end(), 0);
        fill(cnt.begin(), cnt.end(), 0);
        for (size_t i = 0; i < x.size(); i++) {
          if (!vis[i] && (x[i] & (1<<k)) == 0) {
            dfs(i, -1);
          }
        }
        long long total = accumulate(cnt.begin(), cnt.end(), 0);
        total %= mod;
        ans += ((num - total + mod) % mod) * (1 << k) % mod;
        ans %= mod;
      }
      return ans;
    }

    void dfs(int cur, int fa) {
      vis[cur] = 1;
      cnt[cur] = 1;
      for (auto &x : V[cur]) {
        if (x != fa) {
          dfs(x, cur);
          cnt[cur] *= (cnt[x] + 1);
          cnt[cur] %= mod;
        }
      }
    }
};

// CUT begin
ifstream data("SubtreeSum.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> p, vector<int> x, int __expected) {
    time_t startClock = clock();
    SubtreeSum *instance = new SubtreeSum();
    int __result = instance->getSum(p, x);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> p;
        from_stream(p);
        vector<int> x;
        from_stream(x);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, x, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1474259184;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "SubtreeSum (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
