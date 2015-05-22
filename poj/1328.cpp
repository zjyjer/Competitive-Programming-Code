#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

std::vector<std::pair<double, double> > V;
#define sqr(x) (x) * (x)
int main()
{
	int n, d, x, y, t = 1;
	while (scanf("%d %d", &n, &d) == 2 && (n || d)) {
		bool flag = 1;
		if (d < 0)
			flag = 0;
		V.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &x, &y);
			int tmp = sqr(d) - sqr(y);
			if (tmp < 0) {
				flag = 0;	
				continue;
			}
			double l = x - sqrt(tmp);
			double r = x + sqrt(tmp);
			V.push_back(std::make_pair(l, r));
		}
		sort(V.begin(), V.end());
		int ans = 1, curidx = 1;
		double	cur = V[0].second;
		while (curidx < n) {
			while (curidx < n && V[curidx].first <= cur) {
				cur = std::min(cur, V[curidx].second);
				curidx ++;
			}
			if (curidx >= n)
				break;
			ans ++;
			cur = V[curidx].second;
		}
		if (!flag)
			ans = -1;
		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}
