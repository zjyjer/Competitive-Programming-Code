#include <cstdio>

char s[5][5];
int b[5][5] = {0};

void add(int i,int j)
{
	b[i][j] ^= 1;
	for (int k = 0; k < 4; k++)
		b[i][k] ^= 1, b[k][j] ^= 1;
}
int main()
{
	for (int i = 0; i < 4; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < 4; j++)
			if (s[i][j] == '+')
				add(i, j);
	}
	int ans = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ans += b[i][j];
	printf("%d\n", ans);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (b[i][j])
				printf("%d %d\n", i + 1, j + 1);	
	return 0;
}
