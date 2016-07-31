#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp;
	bool vis[1000] = {0};
	int p, q;
	cin >> p;
	while(p--)
	{
		cin >> tmp;
		vis[tmp] = 1;
	}
	cin >> q;
	while(q--)
	{
		cin >> tmp;
		vis[tmp] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			puts("Oh, my keyboard!");
			return 0;
		}
	}
	puts("I become the guy.");
	return 0;
}
