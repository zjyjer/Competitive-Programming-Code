#include <cstdio>
#include <algorithm>
#include <vector>

int pow(int p, int k) {
	int ans = 1;
	while (k --)
		ans *= p;
	return ans;
}

const int maxn = 32768;
int vis[maxn + 10];
std::vector<int> P;
void init() {
	for (int i = 2; i < maxn; i ++) {
		if (!vis[i]) {
			P.push_back(i);
			vis[i] = 1;
			for (int j = i * i; j < maxn; j += i)
				vis[j] = 1;
		}
	}
}

std::vector<std::pair<int, int> >V;
int main()
{
	init();
	while (true) {
		int ans = 1;
		while (true) {
			int p, k;
			scanf("%d", &p);
			if (p == 0)
				return 0;
			scanf("%d", &k);
			ans *= pow(p, k); //p ^ k
			char ch = getchar();
			if (ch != ' ')
				break;
		}
		V.clear();
		ans --;
		for (int i = 0; i < P.size(); i ++) {
			int k = 0;
			if (ans % P[i] == 0) {
				while (ans % P[i] == 0) {
					k ++;
					ans /= P[i];
				}
			}
			if (k) {
				V.push_back(std::make_pair(P[i], k));
			}
		}
		std::reverse(V.begin(), V.end());
		printf("%d %d", V[0].first, V[0].second);
		for (int i = 1; i < V.size(); i ++) {
			printf(" %d %d", V[i].first, V[i].second);
		}
		printf("\n");
	}
	return 0;
}
