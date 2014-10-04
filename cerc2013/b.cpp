#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
int t;
string voice[111];
char ch[111];
bool flag[111];
string tmp;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		bool fl=1;
		int num=0;
		while(fl)
		{
			scanf("%s",ch);
			voice[num++]=string(ch);
			char cc=getchar();
			if(cc=='\n')fl=0;
		}
		while(scanf("%s %s",ch,ch))
		{
			tmp=string(ch);
			if(tmp=="does")
			{
				scanf("%s %s %s",ch,ch,ch);
				break;
			}
			scanf("%s",ch);
			tmp=string(ch);
			for(int i=0;i<num;i++)
			{
				if(voice[i]==tmp)flag[i]=1;
			}
		}
		fl=0;
		for(int i=0;i<num;i++)
		{
			if(!flag[i])
			{
				if(fl)printf(" ");
				cout<<voice[i];
				fl=1;
			}
		}
		printf("\n");
	}
	return 0;
}
