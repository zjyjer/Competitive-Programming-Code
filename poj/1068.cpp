#include <iostream>
#include <stack>
#include <string>

const int maxn = 10010;
int a[maxn];
int b[maxn];
int c[maxn];
int main()
{
	int T;
	std::cin >> T;
	while (T --) {
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++)
			std::cin >> a[i];
		std::string str(a[0], '(');
		str += ")";
		c[0] = str.length() - 1;
		for (int i = 1; i < n; i++) {
			int tmp = a[i] - a[i - 1];
			while (tmp --)
				str += "(";
			str += ")";
			c[i] = str.length() - 1;
		}
		int cur = 0;
		std::stack<int> s;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				s.push(i);
			else {
				b[cur++] = s.top();
				s.pop();
			}
		}
		std::cout << 1;
		for (int i = 1; i < n; i++) {
			int ans = 0;
			for (int j = b[i]; j <= c[i]; j++)
				if (str[j] == ')')
					ans ++;
			std::cout << ' ' << ans;
		}
		std::cout << "\n";
	}
	return 0;
}
