#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x,y;
	double z;
	cin >> x >> y >> z;
	cout << fixed << setprecision(8);
	z/=60;
	int dist=y-x;
	cout << 2*z/dist-z/dist*z/dist << endl;
}