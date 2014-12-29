#include <iostream>
#include <algorithm>
#include <cstring>

int dp[1010];
int c[11], w[11];

int main() 
{
	int C, N;
	std::cin >> C >> N;
	for (int i = 1; i <= N; i++) {
		std::cin >> c[i];
		w[i] = 1;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
		for (int v = c[i]; v <= C; v++)
			dp[v] = std::min(dp[v], dp[v-c[i]]+w[i]);
	std::cout << dp[C] << std::endl;
	return 0;
}
