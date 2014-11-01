#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N, len;
char str[15];

bool ok(int length)
{
	bool flag = 1;
	for(int i = 0; i < length; i++){
		if(str[i] != str[len - length + i]){
			flag = 0;
			break;
		}
	}
	return flag;
}	

int main()
{
	int test_count;
	cin >> test_count;
	for(int cas = 1; cas <= test_count; cas++){
		if(cas != 1) printf("\n");
		printf("Case %d:\n", cas);
		cin >> N >> str;
		long long ans = 0;
		long long power = N;
		len = strlen(str);
		for(int i = 1; i <= len; i++){
			if(ok(i))
				ans += power;
			power *= N;
		}
		cout << ans << "\n";
	}
	return 0;
}
