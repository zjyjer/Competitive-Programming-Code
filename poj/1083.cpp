#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp std::make_pair

std::vector< std::pair<int, int> > V;
int vis[220];

int main()
{
	int cas;
	std::cin >> cas;
	while (cas--) {
		V.clear();
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			std::cin >> a >> b;
			if (a > b)
				std::swap(a, b);
			V.push_back(mp((a + 1) >> 1, (b + 1) >> 1));
		}
		std::sort(V.begin(), V.end());

		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < V.size(); i++) {
			if (!vis[i]) {
				ans ++;
				int cur = V[i].second;
				for (int j = i + 1; j < V.size(); j++) {
					if (!vis[j] && V[j].first > cur) {
						vis[j] = 1;
						cur = V[j].second;
					}
				}
			}
		}
		std::cout << ans * 10 << std::endl;
	}
	return 0;
}
