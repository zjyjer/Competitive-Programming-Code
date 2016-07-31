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

int main()
{

	int n;
	int a[11];
	while(cin >> n)
	{
		memset(a, 0, sizeof(a));
		int ma = 11;
		while(n--)
		{
			int k;
			scanf("%d", &k);
			a[k] ++;
			if(k % 2 == 1)
				ma = min(ma, k);
		}
		if(ma == 11)
		{
			cout << -1 << endl;
			continue;
		}
		int sum = 0;
		for(int i = 1; i < 10; i++)
			sum += a[i];
		if(sum == 1 && a[0])
		{
			cout << -1 << endl;
			continue;
		}
		else
		{
			for(int i = 9; i > ma; i--)
				while(a[i]--)
					printf("%d", i);
			while(a[ma] > 1)
			{
				printf("%d", ma);
				a[ma]--;
			}
			for(int i = ma-1; i >= 0; i--)
			{
				while(a[i]--)
					printf("%d", i);
			}
			printf("%d\n", ma);
		}

	}
	return 0;
}
