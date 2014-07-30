#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	if(m<=n)
		cout << 0;
	else if(m<n+300)
		cout << 1;
	else if(m<n+900)
		cout << 2;
	else if(m<n+1800)
		cout << 3;
	else cout << 4;
}