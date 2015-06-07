#include <iostream>
#include <string>

bool val[10];
std::string str;
int s = 0;
bool solve()
{
	char ch = str[s++];
	while (ch) {
		if (ch >= 'a' && ch <= 'z')	
			return val[ch - 'p'];
		if (ch == 'N')
			return !solve();
		bool f1 = solve(), f2 = solve();
		if (ch == 'K')
			return f1 & f2;
		if (ch == 'A')
			return f1 | f2;
		if (ch == 'E')
			return f1 == f2;
		if (ch == 'C')
			return !f1 | f2;
	}
}
int main()
{
	while (std::cin >> str && str[0] != '0') {
		bool flag = 1;
		for (int sta = 0; sta < 32; sta++) {
			for (int i = 0; i < 5; i++) {
				val[i] = sta & (1 << i);
			}
			s = 0;	
			flag = solve();
			if (flag == 0)
				break;
		}
		if (flag)
			std::cout << "tautology\n";
		else
			std::cout << "not\n";
	}
	return 0;
}
