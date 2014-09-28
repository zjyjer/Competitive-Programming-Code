#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

char str[100010];
int s[100010][30];
int b[100010];
int ss[30];
int k;

bool check(int i, int j)
{
	memset(ss, 0, sizeof(ss));
	for(int p = 0; p < 26; p++)
	{
		ss[p] = s[j][p] - s[i-1][p];
		if(ss[p] > k)
			return false;
	}
	return true;
}	
int main()
{

	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%s", str + 1);
		scanf("%d", &k);
		int len = strlen(str+1);
		for(int i = 0; i < 26; i++)
			s[0][i] = 0;
		for(int i = 1; i <= len; i++)
		{
			for(int j = 0; j < 26; j++)
				s[i][j] = s[i-1][j];
			s[i][str[i]-'a']++;
		}
		int cur = 1;
		for(int i = 1; i <= len; i++)
		{
			while(cur <= len &&check(i, cur))
				cur++;
			b[i] = cur;
		}
		long long ans = 0;
		for(int i = 1; i <= len; i++)
		{
			ans += (long long)(b[i] - i) * (b[i] - i + 1) / 2;
			if(i != 1)
			ans -= (long long)(b[i-1] - i) * (b[i - 1] - i + 1) / 2;
		}
		cout << ans << endl;
	}
	return 0;
}
