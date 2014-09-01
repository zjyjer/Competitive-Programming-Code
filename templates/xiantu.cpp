#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	if(b==0)
		return a;
	else return gcd(b, a%b);
}
struct doge
{
	int a,  b;
};
doge dog[34][5];
int main()
{
	dog[17][0].a=1,dog[17][0].b=1;
	dog[16][0].a=0,dog[16][0].b=1;
	dog[18][0].a=1,dog[18][0].b=0;
	for(int i = 1; i < 5; i++)
	{
		for(int j = 1; j < 34;j++)
		{
			//cout << j << " " << i << endl;
			if(j&1)
			{
				dog[j][i].a=dog[j][i-1].a;
				dog[j][i].b=dog[j][i-1].b;
			}
			else 
				{
					dog[j][i].a=dog[j][i-1].a+dog[j+1][i-1].a;
					dog[j][i].b=dog[j][i-1].b+dog[j+1][i-1].b;
					if(dog[j][i].a && dog[j][i].b)
					{
						int d=gcd(dog[j][i].a, dog[j][i].b);
						dog[j][i].a/=d;
						dog[j][i].b/=d;
					}
				}
			if(dog[j][i].a + dog[j][i].b)
				printf("%d: %d/%d ",j, dog[j][i].a,dog[j][i].b);
		}
		printf("\n");
	}
}