#include <cstdio>
#include <cmath>

int main()
{
	char c1, c2;
	double x, y, t, d, h;
	while (scanf("%c", &c1) && c1 != 'E') {
		t = d = h = 0;
		scanf("%lf %c %lf", &x, &c2, &y);
		getchar();
		if (c1 == 'T')
			t = x;
		else if (c1 == 'D')
			d = x;
		else if (c1 == 'H')
			h = x;
		if (c2 == 'T')
			t = y;
		else if (c2 == 'D')
			d = y;
		else if (c2 == 'H')
			h = y;
		if (h == 0) {
			double e = 6.11 * exp(5417.7530 * (1.0 / 273.16 - 1 / (d + 273.16)));
			h = t + 0.5555 * (e - 10.0);
		}
		else if (d == 0) {
			double e = (h - t) / 0.5555 + 10.0;
			d = 1.0 / 273.16 - log(e / 6.11) / 5417.1530;
			d = 1.0 / d - 273.16;
		}
		else if (t == 0) {
			double e = 6.11 * exp(5417.7530 * (1.0 / 273.16 - 1 / (d + 273.16)));
			t = h - 0.5555 * (e - 10.0);
		}
		printf("T %.1f D %.1f H %.1f\n", t, d, h);		
	}
	return 0;
}
