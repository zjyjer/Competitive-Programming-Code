#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;
char buf[10000];
map<string, int> id;
vector<pair<int, int> >v[600000];
queue<int> q;
int ans1[400000];
int ans2[500000];
bool vis[400000];
string str, sourcename, endname;
const int INF = 1000000000;
int sourcenum, endnum;
int n, m;

void add(int x, int y, int z)
{
	v[x].push_back(make_pair(y,z));
}
void init()
{
	id.clear();
	n = 0;
	scanf("%s", buf);
	bool flag = 0;
	while(1)
	{
		scanf("%s", buf);
		str = buf;
		if(str[str.length()-1] == ',')
			str = str.substr(0, str.length() - 1);
		else
			flag = 1;
		id[str] = ++n;
		if(flag)
			break;
	}

	scanf("%s", buf);
	flag = 0;
	m = 0;
	while(1)
	{
		scanf("%s", buf);
		str = buf;
		if(str[str.length()-1] == ',')
			str = str.substr(0, str.length() - 1);
		else flag = 1;
		m++;
		if(flag)
			break;
	}

	for(int i = 1; i <= n + m + m; i++)
		v[i].clear();

	for(int i = 1; i <= m; i++)
	{
		scanf("%s", buf);
		scanf("%s", buf);
		flag = 0;
		int temp = 0;
		while(1)
		{
			scanf("%s", buf);
			str = buf;
			if(str[str.length()-1] == ',')
				str = str.substr(0, str.length()-1);
			else flag = 1;

			int num = id[str];
			add(num, n + i, -temp);
			add(n + i, num, temp);
			add(num, n + m + i, temp-100000);
			add(n + m + i, num, 100000 - temp);
			temp++;
			if(flag)
				break;
		}
	}

	for(int i = 0; i < 4; i++)
		scanf("%s", buf);
	str = buf;
	sourcename = str;
	sourcenum = id[str];

	for(int i = 0;i < 4; i++)
		scanf("%s", buf);
	str = buf;
	endname = str;
	endnum = id[str];
}

void bfs()
{
	for(int i = 1; i <= n + m + m; i++)
	{
		ans1[i] = INF;
	}
	ans1[sourcenum] = 0;
	while(!q.empty()) q.pop();
	q.push(sourcenum);
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		for(int i = 0; i < (int)v[k].size(); i++)
		{
			int x = v[k][i].first;
			if(ans1[k] + 1 < ans1[x])
			{
				ans1[x] = ans1[k] + 1;
				q.push(x);
			}
		}
	}
}

void spfa()
{
	for(int i = 1; i <= n + m + m; i++){
		ans2[i] = -1000000000;
		vis[i] = 0;
	}

	ans2[sourcenum] = 0;
	vis[sourcenum] = 1;
	q.push(sourcenum);
	while(!q.empty())
	{
		int k = q.front();
		vis[k] = 0;
		q.pop();
		for(int i = 0; i < (int)v[k].size(); i++)
		{
			int x = v[k][i].first, y = v[k][i].second;
			if(ans1[k] + 1 == ans1[x] && ans2[k] + y > ans2[x])
			{
				ans2[x] = ans2[k] + y;
				if(!vis[x])
				{
					q.push(x);
					vis[x] = 1;
				}
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		bfs();
		spfa();
		printf("optimal travel from %s to %s: ", sourcename.c_str(), endname.c_str());
		int a1 = ans1[endnum]/2;
		printf("%d line", a1);
		if(a1 > 1)
			printf("s");
		printf(", ");
		printf("%d minute", ans2[endnum]);
		if(ans2[endnum]>1)
			printf("s");
		printf("\n");
	}
	return 0;
}
