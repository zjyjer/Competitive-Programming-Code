#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

const int maxn = 1000010;
int phi[maxn];
std::bitset<maxn>vis(0);
int pri[80000];
int ansa[maxn];
int ansb[maxn];
int sum[maxn];

void preprocess() {
	//phi
	phi[1] = 1;
	int tot = 0;
	for (int i = 2; i < maxn; i ++) {
		if (!vis[i]) {
			pri[tot++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < tot; j ++) {
			if (i * pri[j] > maxn)
				break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			} else {
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			}
		}
	}
	//ans
	for (int i = 1000001; i >= 1; i --) { //div
		for (int j = i; j < maxn; j += i) {
			if (sum[j] & 1) {
				ansb[j] += (phi[j / i] + 1) / 2 * i;
				ansa[j] += (phi[j / i]) / 2 * i;
			} else {
				ansa[j] += (phi[j / i] + 1) / 2 * i;
				ansb[j] += (phi[j / i]) / 2 * i;
			}
			sum[j] += phi[j / i];
		}
	}
}
int main()
{
	preprocess();
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d %d\n", ansa[n], ansb[n]);
	}
	return 0;
}
