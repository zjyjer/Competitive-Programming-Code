#include <iostream>
#include <cstring>

const int maxn = 300;
char str[maxn];

int main()
{
	while (std::cin.getline(str, 300)) {
		if (str[0] == '#')
			break;
		int ans = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (isalpha(str[i]))
				ans += (str[i] - 'A' + 1) * (i + 1);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
