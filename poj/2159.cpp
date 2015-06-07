#include <iostream>
#include <algorithm>

std::string s1, s2;
int V1[30], V2[30];
int main()
{
	std::cin >> s1 >> s2;
	int len = s1.length();
	for (int i = 0; i < len; i++) {
		V1[s1[i] - 'A'] ++;
		V2[s2[i] - 'A'] ++;
	}
	std::sort(V1, V1 + 26);
	std::sort(V2, V2 + 26);
	bool flag = 1;
	for (int i = 0; i < 26; i++) {
		if (V1[i] != V2[i]) {
			flag = false;
			break;
		}
	}
	if (!flag)
		std::cout << "NO" << std::endl;
	else
		std::cout << "YES" << std::endl;
	return 0;
}
