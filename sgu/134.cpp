#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define pb push_back

const int maxn = 16010;
std::vector<int> V[maxn];
std::vector<int> S;
int n, dp[maxn],s[maxn], ans;

void dfs(int u,int fa)
{
	s[u] = 1;
	for(int i = 0; i < V[u].size(); i++)
	{
		int v = V[u][i];
		if(v != fa){
			dfs(v, u);
			s[u] += s[v];
			dp[u] = std::max(dp[u], s[v]);
		}
	}
	dp[u] = std::max(dp[u], n - s[u]);
	if(dp[u] < ans)
	{
		ans = dp[u];
		S.clear();
		S.pb(u);
	}
	else if(dp[u] == ans)
		S.pb(u);
}
int main()
{
	int a, b;
	scanf("%d", &n);
	for(int i = 0; i < maxn; i++)
		V[i].clear();
	S.clear();
	ans = maxn + 100;
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		V[a].pb(b);
		V[b].pb(a);
	}
	memset(dp, 0, sizeof(dp));
	memset(s, 0, sizeof(s));
	dfs(1,0);
	printf("%d %d\n", ans, (int)S.size());
	std::sort(S.begin(), S.end());
	printf("%d", S[0]);
	for(int i = 1; i < S.size(); i++)
		printf(" %d", S[i]);
	printf("\n");
	return 0;
}
