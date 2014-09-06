#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Circle
{
	double x,y,r;
}a,b;
double eps = 1e-8;
double pi=acos(-1);

double a1;
double sqr(double a)
{
	return a*a;
}
double circins(Circle a,Circle b)
{
	double ans=0;
	double d= sqrt(sqr(a.x-b.x) + sqr(a.y - b.y));
	if(a.r < b.r)
		swap(a,b);
	if (d+eps > a.r + b.r) return 0;
	if (d < a.r - b.r + eps) return pi * sqr(b.r);
	double a1 = acos((sqr(a.r) + d*d - sqr(b.r))/2. /a.r/d);
	double a2 = acos((sqr(b.r) + d*d - sqr(a.r))/2. /b.r /d);
	ans -= d*a.r*sin(a1);
	ans += a1*sqr(a.r) + a2*sqr(b.r);
	return ans;
}

int main()
{
	cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
   	printf("%.3lf\n",circins(a,b));	
	return 0;
}
