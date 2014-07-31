#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct area
{
	double x;
	int num;
}ar[20000];

bool cmp(area m,area n)
{
	return m.x<n.x;
}
int main()
{
	int n,tot=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> ar[i].x >> ar[i].num;
		tot+=ar[i].num;
	}
	sort(ar,ar+n,cmp);
	tot/=2;
	int i=0;
	while(tot>=ar[i].num)
	{
		tot-=ar[i++].num;
	}
	printf("%.5lf\n",ar[i].x);
}