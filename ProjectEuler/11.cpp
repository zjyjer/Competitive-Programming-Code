#include <iostream>
#include <algorithm>
using namespace std;
int a[21][21];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
bool valid(int x, int y)
{
	return (x >= 1) && (x <= 20) && (y >= 1) && (y <= 20);
}
int solve(int x, int y, int dir)
{
	int ans = a[x][y];
	for(int i = 1; i < 4; i++)
	{
		x += dx[dir];
		y += dy[dir];
		if(valid(x, y))
			ans *= a[x][y];
		else return -1;
	}
	return ans;
}

int get(int i, int j)
{
	int ans = -1;
	for(int x = 0; x < 7; x++)
		ans = max(ans, solve(i, j, x));
	return ans;
}
int main()
{
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 20; j++)
			cin >> a[i][j];
	int ans = -1;
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 20; j++)
			ans = max(ans, get(i, j));
	cout << ans << endl;
	return 0;
}

