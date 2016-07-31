#include <iostream>
#include <algorithm>
using namespace std;

long long dp[5000];
int num(int x)
{
	int ret = 0;
	while(x)
	{
		if(x&1) ret++;
		x >>= 1;
	}
	return ret;
}
void solve(long long l, long long r, long long k)
{
	for(int i = 1; i < (1 << (r-l+1)); i++)
	{
		dp[i] = 0;
		if(num(i)>k)
			continue;
		else
		{
			for(int j = 0; j < (r-l+1); j++)
				if(i & (1 << j))
					dp[i] ^= (long long)(l+j);
		}
	}
	long long ans = r*2;
	int idx = 0;
	for(int i = 1; i < (1 << (r-l+1)); i++)
	{
		if(num(i)<=k && dp[i] < ans)
		{
			ans = dp[i];
			idx = i;
		}
	}
	cout << ans << endl;
	cout << num(idx) << endl;
	for(int i = 0; i < (r-l+1); i++)
		if(idx&(1<<i))
			cout << l+i << " ";
	cout << endl;
}

int main()
{
	long long l,r, k;
	cin >> l >> r >> k;
	if(r - l +1 < 10)
	{
		solve(l, r, k);
	}
	else
	{
		if(k==1)
		{
			cout << l << endl << 1 << endl << l << endl;
		}
		else if(k==2)
		{
			if(l&1) l++;
			cout << 1 << endl << 2 << endl << l << " " << l+1 << endl;
		}
		else if(k==3)
		{
			long long minn = 1, midd = 2, maxx = 3;
			while(1)
			{
			//	cout << minn << " " << midd << " " << maxx << endl;
				if(maxx > r)
					break;
				if(minn >= l)
				{
					cout << 0 << endl << 3 << endl;
					cout << minn << " " << midd << " " << maxx << endl;
					return 0;
				}
				minn = minn *2 + 1;
				midd = 2*midd+1;
				maxx = maxx * 2;
			}
			cout << 1 << endl << 2 << endl;
			if(l&1) l++;
			cout << l << " " << l+1 << endl;
		}
		else 
		{
			if(l&1) l++;
			cout << 0 << endl << 4 << endl;
			cout << l << " " << l+1 << "  " << l+2 << " " << l+3 << endl;
		}
	}
	return 0;
}
