#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	for(int i = 1; i <= 200; i++)
	{
		int  sum = 0;
		for(int j = 1; j <= i; j++)
			for(int p = j+1; p <=i; p++)
				for(int q = p+1; q <= i; q++)
					if((p ^ q ^ j) == 0)
						sum+=(p+q+j);
		cout <<i <<" ";
		int k = i;
		while(k)
		{
			cout << k%2;
			k /= 2;
		}
		cout <<' ';
		   cout << sum << ' ';
		while(sum)
		{
			cout << sum%2;
			sum/=2;
		}
		cout << endl;
	}
}
