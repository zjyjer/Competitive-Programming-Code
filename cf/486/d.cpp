#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, d;
const int maxn = 2010;
const int mod = 1000000007;
int val[maxn];
vector<int> V[maxn];

long long dfs(int v, int fa, int root)
{
	long long ans = 1;
	for(int i = 0; i < V[v].size(); i++)
	{
		int u = V[v][i];
		if(u != fa && (val[u] > val[root] || (val[u] == val[root] && u > root)) && val[u] <= val[root] + d)
		{
			ans += ((long long)(dfs(u, v, root)) * ans);
			ans %= mod;
		}
	}
	return ans;
}

int main()
{
	cin >> d >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> val[i];
		V[i].clear();
	}
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += dfs(i, -1, i);
		if(ans >= mod) ans -= mod;
	}
	cout << ans << endl;
}
