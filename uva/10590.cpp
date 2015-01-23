#include <cstdio>
#include <cstring>
#include <algorithm>

const int L = 20;
const int B = 10000;

struct BigInteger {
	BigInteger(int number = 0) : length(!!number) {
		memset(digit, 0, sizeof(digit));
		digit[0] = number;
	}

	BigInteger normalize() {
		while (length && !digit[length - 1]) {
			length --;
		}
		return *this;
	}

	int operator[](int index) const {
		return digit[index];
	}

	int& operator[](int index) {
		return digit[index];
	}

	int length, digit[L];
};

BigInteger operator + (const BigInteger &a, const BigInteger &b)
{
	BigInteger c;
	c.length = std::max(a.length, b.length) + 1;
	for (int i = 0, delta = 0; i < c.length; i++) {
		delta += a[i] + b[i];
		c[i] = delta % B;
		delta /= B;
	}
	return c.normalize();
}

const int maxn = 5001;
BigInteger dp[maxn];

int main()
{
	//freopen("10590.in", "r", stdin);
	dp[0] = 1;
	dp[0].length = 1;
	for (int i = 1; i < maxn; i++) {
		for (int j = i; j < maxn; j++)
			dp[j] = dp[j] + dp[j - i];
	}
	int n;
	while (scanf("%d", &n) == 1) {
		BigInteger &ans = dp[n];
		printf("%d", ans[ans.length - 1]);
		for (int i = ans.length - 2; i >= 0; i--)
			printf("%04d", ans[i]);
		puts("");
	}
	return 0;
}