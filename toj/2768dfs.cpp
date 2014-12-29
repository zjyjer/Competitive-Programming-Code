#include <iostream>
#include <cstring>
#include <algorithm>

#define debug(x) std::cout << #x << ' ' << x << std::endl;
int C,N, sol;
int c[12];
void dfs(int ret, int num, int ans)
{
	if (!ret) {
		sol = std::min(sol, ans);
		return;
	}
	if(ans > sol) return;
	if(num > N) return;
	int k = ret / c[num];
	for(int i = 0; i <= k; i++)
		dfs(ret - i * c[num], num+1, ans+i);
}
int main()
{
	sol = 1010;
	std::cin >> C >> N;
	for (int i = 1; i <= N; i++)
		std::cin >> c[i];
	dfs(C, 1, 0);
	debug(sol);
	return 0;
}
