#include <cstdio>
#include <cstring>

int n, m, w;
int a[100010];
long long st[100010];

inline long long f(int i)
{
	if(i<w)
		return st[i-1] - st[0];
	else return st[i-1] - st[i-w];
}
bool check(int x)
{
	memset(st, 0, sizeof(st));
	long long ans  = 0;
	st[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		long long s = x - a[i] - f(i);
		if(s > 0)
		{
			st[i] = st[i-1] + s;
			ans += s;
		}
		else st[i] = st[i-1];
	}
	if(ans <= m) return true;
	else return false;	
}

int main()
{
	scanf("%d %d %d", &n, &m, &w);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int low = 1, high = 1e9+1e6;
	int mid;
	while(low < high)
	{
		mid = (low + high)/2 + 1;
		if(check(mid))
			low = mid;
		else high = mid - 1;
	}
	printf("%d\n",low);
	return 0;
}
