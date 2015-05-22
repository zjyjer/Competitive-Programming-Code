#include <iostream>

int main()
{
	int s, d;
	while (std::cin >> s >> d) {
		int ans = -1;
		for (int i = 4; i >= 1; i--) {
			int tmp = i * s - (5 - i) * d;
			if (tmp < 0) {
				ans = std::max(ans, 2 * tmp + s + (i >= 2 ? s : -d));
				break;
			}
		}
		if (ans < 0)
			std::cout << "Deficit" << std::endl;
		else
			std::cout << ans << std::endl;
	}
	return 0;
}
