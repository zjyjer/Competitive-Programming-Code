#include <cstdio>

int arr[1510];
int main()
{
	int a,al,be,ga,m,k;
	scanf("%d %d %d %d %d",&a,&al,&be,&ga,&m);
	arr[0]=a%m;
	for(int i=1;i<=1500;i++)
	{
		arr[i]=(al*arr[i-1]*arr[i-1]+be*arr[i-1]+ga)%m;
	}
	int step=0;
	int start=0;
	for(int i=1;i<=1500;i++)
		{
			for(int j=0;j<i;j++)
				if(arr[i]==arr[j])
				{
					step=i-j;
					start=j;
					break;
				}
			if(step) break;
		}
	//printf("%d %d\n",step,start);
	scanf("%d",&k);
	if(k==0)
	{
		printf("%d\n",a);
		return 0;
	}
	if(k>start)
	{
		k-=start;
	    k%=step;
	    k+=start;
	}
	printf("%d\n",arr[k]);
}
