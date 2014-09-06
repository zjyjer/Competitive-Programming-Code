#include <iostream>
using namespace std;

int main()
{
	for(long long i = 1; i <= 1000000l; i++)
	{
		if((i^(2*i)) > 3*i)
			cout << i << endl;
	}
	return 0;
}
