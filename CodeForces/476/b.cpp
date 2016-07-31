#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

char s1[15], s2[15];
int c[15][15] = {0};

int main()
{
	for(int i = 1; i < 15; i++)
	{
		c[i][0] = 1;
		c[i][1] = i;
		for(int j = 2; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	cin >> s1 >> s2;
	int len = strlen(s1);
	int t1 = 0, t2 =0 ;
	int q1 = 0, q2 = 0;
	for(int i = 0; i < len; i++)
	{
		if(s1[i] == '+')
			t1++;
		if(s2[i] == '+')
			t2++;
		if(s2[i] == '?')
			q2++;
	}
	if(t1 == t2 && q2 == 0)
		cout << fixed << setprecision(9) << 1.0 << endl;
	else if(t1 > t2 + q2)
		cout << fixed << setprecision(9) << 0.0 << endl;
	else cout << fixed << setprecision(9) << c[q2][t1 - t2] * 1.0 / (1 << q2) << endl;
	return 0;
}
