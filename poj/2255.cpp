#include <iostream>
#include <string>
#include <algorithm>

std::string s1, s2;

std::string solve(std::string s1, std::string s2) {
	int len = s1.length();
	if (len <= 0)
		return "";
	int idx = s2.find(s1[0]);
	std::string tmp1 = solve(s1.substr(1, idx), s2.substr(0, idx));
	std::string tmp2 = solve(s1.substr(idx + 1, len - idx - 1), s2.substr(idx + 1, len - idx - 1)); 
	return tmp1 + tmp2 + s1[0];
}

int main()
{
	while (std::cin >> s1 >> s2) {
		std::string ans = solve(s1, s2);
		std::cout << ans << std::endl;
	}
	return 0;
}
