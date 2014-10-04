#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;
long long a[maxn];
vector<pair<long long, int> >v, vcur;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		v.clear();
		v.push_back(make_pair(a[1],1));
		long long ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			vcur.clear();
			vcur.push_back(make_pair(a[i], 1));
			for(int j = 0; j < (int)v.size(); j++)
			{
				long long gcd = __gcd(v[j].first, a[i]);
				if(gcd == vcur[vcur.size()-1].first)
					vcur[vcur.size()-1].second = v[j].second + 1;
				else
					vcur.push_back(make_pair(gcd, v[j].second + 1));
			}
			v = vcur;
			for(int j = 0; j < (int)v.size(); j++)
				ans = max(ans, v[j].first * v[j].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
