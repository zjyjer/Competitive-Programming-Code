#include <iostream>
using namespace std;

int main()
{
	int n,s;
	cin >> n >> s;
	bool ok = 0;
	int x,y,sol=100;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if(x < s && y!=0)
		{
			sol = min(sol, y);
		}
		if(x < s || (x==s && y==0))
			ok=1;
	}
	if(!ok)
		cout << -1 << endl;
	else cout << 100-sol << endl;
	return 0;
}
