#include <cstdio>

void zeller(int y,int m,int d)
{
	if(m<=2)
		y--,m+=12;
	int c=y/100;
	y%=100;
	int w=((c>>2)-(c<<1)+y+(y>>2)+(13*(m+1)/5)+d-1)%7;
	if(w<=0)
		w+=7;
	printf("%d\n",w);
}
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)==2)
	{
		if(m>a[n-1]) {printf("Impossible\n");continue;}
		//printf("%d\n",zeller(2001,n,m));
		zeller(2001,n,m);
	}
	return 0;
}