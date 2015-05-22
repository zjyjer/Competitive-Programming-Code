#include <iostream>
#include <cmath>

int main()
{
	int n;
	double p;
	while (std::cin >> n >> p) {
		std::cout << exp(log(p) / n) << std::endl;
	}
	return 0;
}
