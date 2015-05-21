#include <cstdio>
#include <cstring>

char g[7][7];
int b[7][7];

int getnum(int s) {
	int ans = 0;
	while (s) {
		ans += (s & 1);
		s >>= 1;
	}
	return ans;
}
void flip(int i, int j)
{
	b[i - 1][j] ^= 1;
	b[i + 1][j] ^= 1;
	b[i][j - 1] ^= 1;
	b[i][j + 1] ^= 1;
	b[i][j] ^= 1;
}

int main()
{
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%c", &g[i][j]);
			if (g[i][j] == 'w')
				b[i][j] = 1;
		}
		getchar();
	}
	int ans = 20;
	for (int s = 0; s < (1 << 16); s++) {
		int num = getnum(s);
		if (num >= ans)
			continue;
		for (int i = 0; i < 16; i++) {
			if (s & (1 << (i))) {
				flip(i % 4 + 1, i / 4 + 1);
			}
		}
		bool flag = 1;
		int tmp = 0;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				tmp += b[i][j];
		if (tmp && tmp != 16)
			flag = 0;
		if (flag)
			ans = num;
		for (int i = 0; i < 16; i++) {
			if (s & (1 << (i))) {
				flip(i % 4 + 1, i / 4 + 1);
			}
		}
	}
	if (ans < 20)
	printf("%d\n", ans);
	else
		printf("Impossible\n");
	return 0;
}
