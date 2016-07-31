#include <iostream>
#include <algorithm>

unsigned long long a[151];
unsigned long long base[100];
unsigned long long ans [150];
int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		for (int j = 0; j < 64; j ++) {
			if ((1LL << j) & a[i]) {
				a[i] ^= base[j];
			}
		}
		if (a[i]) {
			int j;
			for (j = 63; j >= 0; j --) {
				if ((1LL << j) & a[i]) {
					base[j] = a[i];
					break;
				}
			}
			for (int k = 63; k >= 0; k --) {
				if (k != j && base[k] & (1LL << j))
					base[k] ^= base[j];
			}
		}
		for (int j = 63; j >= 0; j --) {
			if (base[j])
				ans[i + 1] ^= base[j];
		}
	}
	unsigned long long sol = 0;
	for (int i = 1; i <= n; i++)
			sol = std::max(ans[i], sol);
	std::cout << sol << std::endl;
	return 0;
}
