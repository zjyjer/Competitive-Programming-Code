#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<stdio.h>
#include<queue>
using namespace std;

const double eps=1e-8,pi=acos(-1.0);

int cmp(double x)
{
	if(fabs(x)<eps)return 0;
	if(x>0)return 1;
	return -1;
}
class Point
{
public:
	double x,y;
	Point(double a=0,double b=0){
		x=a,y=b;
	}
	Point operator + (const Point &b){
		return Point(x+b.x,y+b.y);
	}
	Point operator - (const Point &b){
		return Point(x-b.x,y-b.y);
	}
	bool operator == (const Point &b){
		return cmp(x-b.x)==0&&cmp(y-b.y)==0;
	}
	Point operator * (const double &a){
		return Point(a*x,a*y);
	}
	friend Point operator * (const double &a,const Point &b){
		return Point(b.x*a,b.y*a);
	}
	Point operator / (const double &a){
		return Point(x/a,y/a);
	}
	double length(){
		return sqrt(x*x+y*y);
	}
	double dot(const Point &a){
		return x*a.x+y*a.y;//向量点积
	}
	double det(const Point &a){
		return x*a.y-y*a.x;//向量叉积
	}
	double dist(const Point &a){
		return Point(a.x-x,a.y-y).length();
	}
	Point rotate(const double &A){//逆时针旋转
		*this=Point(x*cos(A)-y*sin(A),x*sin(A)+y*cos(A));
		return *this;
	}
	bool operator < (const Point & p)const{//水平序
		return cmp(x-p.x)<0 || cmp(x-p.x)==0 && cmp(y-p.y)<0;
	}
};
class Line
{//线段
public:
	Point a,b;
	Line(Point x=Point(),Point y=Point()){
		a=x,b=y;
	}
	double dist(Point p){//点到线段的距离
		if(cmp((p-a).dot(b-a))<0)return (p-a).length();
		if(cmp((p-b).dot(a-b))<0)return (p-b).length();
		return fabs((a-p).det(b-p)/a.dist(b));
	}
	Point foot(Point p){//垂足
		double r=(b-a).dot(p-a)/(b-a).dot(b-a);
		return a+r*(b-a);
	}
	bool online(Point p){//点在线段上
		return cmp((p-a).det(b-a))==0 && cmp((p-a).dot(p-b))<=0;
	}
	bool parallel(Line l){
		return !cmp((a-b).det(l.a-l.b));
	}
	bool cross(Line l,Point &res){//直线交点
		if(this->parallel(l))return false;
		double s1=(a-l.a).det(l.b-l.a),s2=(b-l.a).det(l.b-l.a);
		res=(s1*b-s2*a)/(s1-s2);
		return true;
	}
	double arg()
	{
		Point p=b-a;
		if(p.x==0)
		{
			if(p.y==0)return 0;
			else if(p.y>0)return pi/2;
			else if(p.y<0)return 3*pi/2;
		}
		if(p.y==0)
		{
			if(p.x>0)return 0;
			else if(p.x<0)return pi;
		}
		double ar=fabs(p.y/p.x);
		ar=atan(ar);
		if(p.x<0&&p.y>0)ar=pi-ar;
		else if(p.x<0&&p.y<0)ar+=pi;
		else if(p.y<0)ar=2*pi-ar;
		return ar;
	}
};

double getarea(vector<Point> arr,int n)
{
	double area=0;
	arr.push_back(arr[0]);
	for(int i=0;i<n;i++)
		area+=arr[i+1].det(arr[i]);
	arr.pop_back();
	return fabs(area/2);
}
int inpolygon(vector<Point> arr,int n,Point p)
{
	int num=0,d1,d2,k;
	arr.push_back(arr[0]);
	for(int i=0;i<n;i++)
	{
		if(Line(arr[i+1],arr[i]).online(p))return 2;//在边界上
		k=cmp((arr[i+1]-arr[i]).det(p-arr[i]));
		d1=cmp(arr[i].y-p.y),d2=cmp(arr[i+1].y-p.y);
		if(k>0&&d1<=0&&d2>0)num++;
		if(k<0&&d2<=0&&d1>0)num--;
	}
	arr.pop_back();
	return num!=0;//0表示在多边形外，1在多边形内
}
Point Gcenter(vector<Point> arr,int n)
{//重心
	Point ans=Point(0,0);
	double area=getarea(arr,n);
	if(cmp(area)==0)return ans;//无意义
	arr.push_back(arr[0]);
	for(int i=0;i<n;i++)
		ans=ans+(arr[i]+arr[i+1])*arr[i+1].det(arr[i]);
	arr.pop_back();
	return ans/area/6.0;
}

bool satisfy(Point a,Line p)
{//半平面交辅助函数
	return cmp((a-p.a).det(p.b-p.a))<=0;
}
bool cmpLine(Line a,Line b)
{//半平面极角序
	int res=cmp(a.arg()-b.arg());
	return res==0?satisfy(a.a,b):res<0;
}
class Convex
{
public:
	vector<Point> p;
	Convex(int n=0){
		p.resize(n);
	}
	Convex get(vector<Point> v)
	{//获取凸多边形
		p.resize(2*v.size()+5);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		int m=0;
		for(int i=0;i<v.size();i++)
		{
			while(m>1&&cmp((p[m-1]-p[m-2]).det(v[i]-p[m-2]))<=0)
				m--;
			p[m++]=v[i];
		}
		int k=m;
		for(int i=int(v.size())-2;i>=0;--i)
		{
			while(m>k&&cmp((p[m-1]-p[m-2]).det(v[i]-p[m-2]))<=0)
				m--;
			p[m++]=v[i];
		}
		p.resize(m);
		if(v.size()>1)p.resize(m-1);
		return *this;
	}
	bool contain(Point r)//在内部或边界上
	{//logN
		int n=p.size();
		Point g=(p[0]+p[n/3]+p[2*n/3])/3.0;
		int l=0,h=n;
		while(l+1<h)
		{
			int mid=(l+h)/2;
			if(cmp((p[l]-g).det(p[mid]-g))>0)
			{
				if(cmp((p[l]-g).det(r-g))>=0&&cmp((p[mid]-g).det(r-g))<0)
					h=mid;
				else l=mid;
			}
			else
			{
				if(cmp((p[l]-g).det(r-g))<0&&cmp((p[mid]-g).det(r-g))>=0)
					l=mid;
				else h=mid;
			}
		}
		h%=n;
		int z=cmp((p[h]-r).det(p[l]-r))-1;
		if(z==-2)return 1;
		return z;
	}
	double diameter(int &first,int &second)
	{
		double maxd=0;
		int n=p.size();
		if(n==1)
			first=second=0;
		else
		{
			for(int i=0,j=1;i<n;i++)
			{
				while(cmp((p[(i+1)%n]-p[i]).det(p[j]-p[i])
					-(p[(i+1)%n]-p[i]).det(p[(j+1)%n]-p[i]))<0)
					j=(j+1)%n;
				double d=p[i].dist(p[j]);
				if(d>maxd)
				{
					maxd=d;
					first=i,second=j;
				}
				d=p[(i+1)%n].dist(p[(j+1)%n]);
				if(d>maxd)
				{
					maxd=d;
					first=i,second=j;
				}
			}
		}
		return maxd;
	}
	Convex halfplaneIntersection(vector<Line> v)
	{//半平面交
		sort(v.begin(),v.end(),cmpLine);
		deque<Line> q;
		deque<Point> ans;
		q.push_back(v[0]);
		Point cro;
		for(int i=1;i<int(v.size());i++)
		{
			if(cmp(v[i].arg()-v[i-1].arg())==0)
				continue;
			while(ans.size()>0&&!satisfy(ans.back(),v[i]))
			{
				ans.pop_back();
				q.pop_back();
			}
			while(ans.size()>0&&!satisfy(ans.front(),v[i]))
			{
				ans.pop_front();
				q.pop_front();
			}
			q.back().cross(v[i],cro);
			ans.push_back(cro);
			q.push_back(v[i]);
		}
		while(ans.size()>0&&!satisfy(ans.back(),q.front()))
		{
			ans.pop_back();
			q.pop_back();
		}
		while(ans.size()>0&&!satisfy(ans.front(),q.back()))
		{
			ans.pop_front();
			q.pop_front();
		}
		q.back().cross(q.front(),cro);
		ans.push_back(cro);
		p=vector<Point> (ans.begin(),ans.end());
		return *this;
	}
	Convex convexIntersection(Convex v1,Convex v2)
	{//凸多边形交
		vector<Line> h;
		int n1=v1.p.size(),n2=v2.p.size();
		for(int i=0;i<n1;i++)
			h.push_back(Line(v1.p[i],v1.p[(i+1)%n1]));
		for(int i=0;i<n2;i++)
			h.push_back(Line(v2.p[i],v2.p[(i+1)%n2]));
		(*this).halfplaneIntersection(h);
		return *this;
	}
};

class Circle
{
public:
	Point c;
	double r;
	Circle(Point p=Point(),double d=0){
		c=p,r=d;
	}
	int cross(Line line,Point p1[],bool flag=0)
	{//flag=0表示与线段的交点，否则为直线
		int num=0;
		double dx=line.b.x-line.a.x,dy=line.b.y-line.a.y;
		double A=dx*dx+dy*dy,B=2*dx*(line.a.x-c.x)+2*dy*(line.a.y-c.y),
		   C=(line.a.x-c.x)*(line.a.x-c.x)+(line.a.y-c.y)*(line.a.y-c.y)-r*r;
		double delta=B*B-4*A*C;
		if(cmp(delta)>=0)
		{
			if(delta<0)delta=0;
			double t1=(-B-sqrt(delta))/2/A,
				   t2=(-B+sqrt(delta))/2/A;
			p1[num++]=Point(line.a.x+t1*dx,line.a.y+t1*dy);
			if(!(cmp(t1-1)<=0&&cmp(t1)>=0)&&!flag)num--;
			p1[num++]=Point(line.a.x+t2*dx,line.a.y+t2*dy);
			if((!cmp(t2-1)<=0&&cmp(t2)>=0)&&!flag)num--;
		}
		return num;
	}
	double area(Circle p)
	{//两圆相交面积
		Point a=this->c,b=p.c;
		double r1=r,r2=p.r;
		double ans=0,d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
		if(r1<r2)
			swap(a,b),swap(r1,r2);
		if(d+eps>r1+r2)return 0;
		if(d<r1-r2+eps)return pi*r2*r2;
		double a1=acos((r1*r1+d*d-r2*r2)/2/r1/d),
			a2=acos((r2*r2+d*d-r1*r1)/2/r2/d);
		ans-=d*r1*sin(a1);
		ans+=a1*r1*r1+a2*r2*r2;
		return ans;
	}
	bool in(Point p){
		return cmp((p-c).length()-r)<0;
	}
	Circle threepoint(Point p0,Point p1,Point p2)
	{
		double a1=p1.x-p0.x,b1=p1.y-p0.y,c1=(a1*a1+b1*b1)/2;
		double a2=p2.x-p0.x,b2=p2.y-p0.y,c2=(a2*a2+b2*b2)/2;
		double d=a1*b2-a2*b1;
		c.x=p0.x+(c1*b2-c2*b1)/d;
		c.y=p0.y+(a1*c2-a2*c1)/d;
		r=c.dist(p0);
		return *this;
	}
	Circle mincircle(Point a[],int n)
	{
		if(n==0)return *this;
		c=a[0];
		r=0;
		for(int i=1;i<n;i++)
		{
			if(!in(a[i]))
			{
				c=a[i],r=0;
				for(int j=0;j<i;j++)
					if(!in(a[j]))
					{
						c=Point((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2);
						r=(a[j]-c).length();
						for(int k=0;k<j;k++)
							if(!in(a[k]))threepoint(a[i],a[j],a[k]);
					}
			}

		}
		return *this;
	}
};
int main()
{
	return 0;
}
