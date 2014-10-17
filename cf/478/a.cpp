#include <iostream>
using namespace std;

int main()
{
	int sum = 0, tmp;
	for(int i = 0; i < 5; i++)
	{
		cin >> tmp;
		sum += tmp;
	}
	if(sum && sum % 5 == 0)
		cout << sum / 5 << endl;
	else cout << -1 << endl;
	return 0;
}
