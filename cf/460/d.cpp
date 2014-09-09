#include <iostream>
using namespace std;

int main()
{
	long long l, r, k;
	cin >> l >> r >> k;
	if(k > 4 || ((k==4) && !(l&1)) || ((k==4) && (r-l>=4)))
	{
		cout << 0 << endl;
		cout << 4 << endl;
		if(l&1) l++;
		for(int i = 0; i < 4; i++)
			cout << i + l << " ";
	}
	else if(k==1)
	{
		cout << l << endl;
		cout << 1 << endl;
		cout << l << endl;
	}
	else if(k==2)
	{
		cout << 1 << endl;
		cout << 2 << endl;
		cout << l << " " << l + 1 << endl;
	}
	else if(k==4)	
	{
		for(int i = 0; i <=15; i++)
			for(int j = 0; j < 4; j++)
			{
				if(i&(1<<j))


