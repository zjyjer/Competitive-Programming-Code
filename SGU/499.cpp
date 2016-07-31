#include <iostream>
using namespace std;

const int maxn = 1000100;
int num[maxn] = {0};
int main()
{
	int n, tmp;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> tmp;
		num[tmp]++;
	}
	for(int i = maxn; i >= 1; i--)
	{
		int ans = 0;
		for(int j = i; j  < maxn; j += i)
			ans += num[j];
		if(ans > 1)
		{
			cout << i << endl;
			return 0;
		}
	}
}
