#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("a.in","r",stdin);
	int a[26];
	memset(a,0,sizeof(a));
	char s;
	while(cin >> s && s!='}')
	{
		if(s>='a' && s<='z')
			a[s-'a']++;
	}
	int ans=0;
	for (int i=0;i<26;i++)
	{
		if(a[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}