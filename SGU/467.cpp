#include <iostream>
#include <cstdio>

int main(){
	int cas = 0, p;
	//freopen("467.in", "r", stdin);
	while(std::cin>>p) {
		printf("Case #%d: ", ++cas);
		if (p == 0)
			std::cout << 0 << std::endl;
		else if (p <= 78)
			std::cout << 1 << std::endl;
		else if(p <= 95)
			std::cout << 2 << std::endl;
		else if (p <= 99)
			std::cout << 3 << std::endl;
		else
			std::cout << 4 << std::endl;
	}
	return 0;
}
