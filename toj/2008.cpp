#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

const int maxn = 1005;
struct point {
	int x, y;
	point() {}
	point(int a, int b): x(a), y(b) {}
	void read() {
		scanf("%d %d", &x, &y);
	}
	friend point operator - (const point &a, const point &b) {
		return point(a.x - b.x, a.y - b.y);
	}
	friend point operator / (const point &a, const int &b) {
		return point(a.x / b, a.y / b);
	}
	friend bool operator < (const point &a, const point &b) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	friend bool operator == (const point &a, const point &b) {
		return a.x == b.x && a.y == b.y;
	}
}P[maxn];

std::multiset<point> S;
std::vector<point> V;

int main() {
	int cas = 1, n;
	int a, b;
	while (std::cin >> a >> b)
		std::cout << std::__gcd(a, b) << std::endl;
	while (scanf("%d", &n) && n) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			P[i].read();
		std::sort(P + 1, P + n + 1);
		for (int i = 1; i <= n; i++) {
			S.clear();
			V.clear();
			for (int j = i + 1; j <= n; j++) {
				point seg = point(P[j] - P[i]);			
				if (seg.x == 0) seg.y = 1;
				if (seg.y == 0) seg.x = 1;
				int gcd = std::__gcd(seg.x, seg.y);
				seg = seg / gcd;
				if(seg.x < 0) seg = seg / -1;
				S.insert(seg);
				V.push_back(seg);	
			}
			std::sort(V.begin(), V.end());
			int size = std::unique(V.begin(), V.end()) - V.begin();
			for (int i = 0; i < size; i++) {
				ans = std::max(ans, (int)S.count(V[i]) + 1);
			}
		}
		if(ans < 4) ans = 0;
		printf("Photo %d: %d points eliminated\n", cas++, ans);
	}
	return 0;
}
