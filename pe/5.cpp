#include <iostream>
using namespace std;

long long cur = 1;
long long ans[45];

int gcd(long long a, long long b)
{
	if(a < b)
		swap(a, b);
	if(b==0)
		return a;
	else return gcd(a%b, b);
}
void init()
{
	ans[1] = 1;
	cur = 1;
	for(int i = 2; i <= 40; i++)
	{
		int k = gcd((long long)i, cur);
		k = i / k;
		cur *= k;
		ans[i] = cur;
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
