#include <iostream>
#include <algorithm>

using namespace std;

int cnt[1000010] = {0};
int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0){
		x = 1; y = 0;
		return a;
	} else {
		int r = exgcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

int sol(int a, int b, int n)
{
	int x, y;
	int d = exgcd(a, n, x, y);
	return (long long)x * b % n;
}

int main()
{
	int n, m, dx, dy;
	cin >> n >> m >> dx >> dy;
	int x, y;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		int k = sol(dx, x, n);
		int yy = (y - ((long long)k * dy % n) + n) % n;
		cnt[yy]++;
	}
	int ans = 0, index = 0;
	for(int i = 0; i < n; i++)
		if(cnt[i] > ans)
		{
			ans = cnt[i];
			index = i;
		}
	cout << 0 << ' ' << index << endl;
	return 0;
}
