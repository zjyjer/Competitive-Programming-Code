#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
	int p1[3], p2[3];
	void read()
	{
		for(int i = 0; i < 3; i++)
			scanf("%d", &p1[i]);
		for(int i = 0; i < 3; i++)
		{
			scanf("%d", &p2[i]);
			if(p1[i] > p2[i])
				swap(p1[i], p2[i]);
		}
	}
}p[1000100];
const int INF = 1000000000;
int n;
bool work(int x)
{
	int s = 0;
	for(int i = 1; i <= n; i++)
		if(p[i].p1[x] == p[i].p2[x])
			s++;
	if(!(s && (n - s)))
		return 0;

	int left[3] = {-INF, -INF, -INF};
	int right[3] = {INF, INF, INF};
	for(int i = 1; i <= n; i++)
	{
		if(p[i].p1[x] != p[i].p2[x])
		{
			for(int j = 0; j < 3; j++)
			{
				left[j] = max(left[j], p[i].p1[j]);
				right[j] = min(right[j], p[i].p2[j]);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(p[i].p1[x] == p[i].p2[x])
		{
			for(int j = 0; j < 3; j++)
			{
				if(p[i].p2[j] < left[j] || p[i].p1[j] > right[j])
					return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			p[i].read();
		bool flag = 0;
		for(int i = 0; i < 3; i++)
		{
			if(work(i))
			{
				printf("YES\n");
				flag = 1;
				break;
			}
		}
		if(!flag)
		printf("NO\n");
	}
	return 0;
}
