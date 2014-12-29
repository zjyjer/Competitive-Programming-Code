#include <iostream>
#include <vector>
#include <algorithm>

#define debug(x) std::cout << #x << ' ' << x << std::endl;
std::vector<int> V;
const int maxn = 1000010;
int divsum[maxn + 5] = {0};
int size;

void pre()
{
	for (int i = 1; i <= maxn; i++)
		for (int j = i * 2; j <= maxn; j += i)
			divsum[j] += i;
	for (int i = 1; i <= maxn; i++) {
		if (divsum[i] == i)
			V.push_back(i);
		else if (divsum[i] <= maxn && divsum[divsum[i]] == i)
			V.push_back(std::max(divsum[i], i));
	}
	std::sort(V.begin(), V.end());
	size = std::unique(V.begin(),V.end()) - V.begin();
}
int main() 
{
	int cas;
	std::cin >> cas;
	V.clear();
	pre();
	while (cas--) {
		int n;
		std::cin >> n;
		std::cout << std::upper_bound(V.begin(), V.begin() + size, n) - V.begin() << std::endl;
	}
	return 0;
}
