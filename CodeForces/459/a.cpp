#include <iostream>
using namespace std;

int abs(int x)
{
	if(x <= 0)
		return -x;
	return x;
}
int main()
{
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	if(sx ==dx)
	{
		cout << sx + abs(sy-dy) << " " << sy << " " << dx + abs(sy-dy) << " " << dy << endl;
	}
	else if(sy == dy)
	{
		cout << sx << " " << sy+abs(sx-dx) << " " << dx <<" " << dy + abs(sx - dx) << endl;
	}
	else 
	{
		int x = abs(sx-dx);
		int y = abs(sy-dy);
		if(x!=y)
		{
			cout << -1 << endl;
			return 0;
		}
		else cout << dx << " " << sy << " " << sx << " " << dy << endl;
	}
	return 0;
}
