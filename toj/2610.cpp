#include <iostream>

const int size = 1211;
bool vis[size + 5] = {0};
int dp[size][15] = {1};
int p[size];
int main() {
	int tot = 0;
	for (int i = 2; i <= size; i++) {
		if(!vis[i])
			p[tot++] = i;
		for (int j = i * i; j <= size; j += i)
			vis[j] = 1;	
	}
	for (int i = 0; i < tot; i++) {
		for (int j = 14; j > 0; j--) {
			for(int k = p[i]; k < size; k++) 
				dp[k][j] += dp[k - p[i]][j - 1];
		}
	}
	int n, k;
	while (std::cin >> n >> k && n && k)
		std::cout << dp[n][k] << std::endl;	
	return 0;
}
