#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("a.in","r",stdin);
	char s[250];
	int k;
	cin >> s>>k;
	int len=strlen(s);
	int ans=0;
	bool flag=1;
	if(k>=len)
	{
		cout << k+len-(k+len)%2 << endl;
		return 0;
	}
	for(int i=1;i<=(len - k )/2;i++)
	{
		flag=1;
		for(int j=1;j<=i;j++)
		{
			//cout << s[len-j] << " " << s[len-j-i-k] << endl;
			if(s[len-j]!=s[len-j-i-k])
				{
					flag=0;
					break;
				}
		}
		if(flag)
			ans=i;
	}

	
	cout << 2*(ans+k) << endl;
	return 0;
}