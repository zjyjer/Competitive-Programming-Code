#include<iostream>
using namespace std;
int x, y;
int m[110][110];
int a[110][110];
int r[120], c[120];
bool flag;

int main()
{
	cin >> x >> y;
	for(int i = 1; i <= 110; i++)
		r[i] = c[i] = 0;
	flag = 0;
	for(int i = 1; i <= x; i++)
		for(int j = 1; j <= y; j++)
		{
			cin >> m[i][j];
			if(m[i][j]) flag = 1;
			r[i] += m[i][j];
			c[j] += m[i][j];
		}
	bool flag2 = 0;	
	for(int i = 1; i <= x; i++)
		for(int j = 1; j <= y; j++)
		{
			if(m[i][j])
			{
				if(r[i] == y && c[j] == x)
				{
					a[i][j] = 1;
					flag2 = 1;
				}
				else if(r[i] != y && c[j] != x)
				{
					cout << "NO" << endl;
					return 0;
				}
				else a[i][j] = 0;
			}
			else a[i][j] = 0;
		}
	if(flag2 != flag)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 1; i <= x; i++)
	{
		for(int j = 1; j <= y; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
