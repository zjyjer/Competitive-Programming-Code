#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
//using namespace std;
typedef long long ll;
const int maxn = 100010;
int ansn;
long long abs(ll n)
{
	if(n < 0)
		return -n;
	return n;
}
ll ans[1000000];
ll mulmod(ll a,ll b, ll mod)
{
	ll d = (ll)((long double)a * b / mod);
	d = a * b - mod * d;
	while(d < 0) d += mod;
	while(d >= mod) d -= mod;
	return d;
}
ll myrand()
{
	ll a = rand();
	a *= rand();
	return abs(a);
}
ll powmod(ll a, ll n, ll mod)
{
	ll ret = 1;
	while(n){
		if(n & 1) ret = mulmod(ret,a,mod);
		a = mulmod(a, a, mod);
		n >>= 1;
	}
	return ret;
}
ll gcd(ll a, ll b)
{
	if(a < b) std::swap(a, b);
	if(b == 0)
		return a;
	else return gcd(b, a % b);
}
long long strong_pseudo_primetest(long long n, int base) {
	long long n2 = n - 1, res;
	int s = 0;
	while (n2 % 2 == 0) n2>>=1, s++;
	res = powmod(base, n2, n);
	if((res == 1) || (res == n - 1)) return 1;
	s--;
	while(s >= 0) {
		res = mulmod(res, res, n);
		if(res == n - 1) return 1;
		s--;
	}
	return 0; //n is not a strong pseudo prime
}

int isprime(long long n) {
	if(n < 2) return 0;
	if(n < 4) return 1;
	if(strong_pseudo_primetest(n,2) == 0) return 0;
	if(strong_pseudo_primetest(n,3) == 0) return 0;
	if(n < 1373653LL) return 1;
	if(strong_pseudo_primetest(n,5) == 0) return 0;
	if(n < 2532600LL) return 1;
	if(strong_pseudo_primetest(n,7) == 0) return 0;
	if(n == 3215031751LL) return 0;
	if(n < 25000000000LL) return 1;
	if(strong_pseudo_primetest(n,11) == 0) return 0;
	if(n < 2152302898747LL) return 1;
	if(strong_pseudo_primetest(n,13) == 0) return 0;
	if(n < 3474749660383LL) return 1;
	if(strong_pseudo_primetest(n,17) == 0) return 0;
	if(n < 341550071728321LL) return 1;
	if(strong_pseudo_primetest(n,19) == 0) return 0;
	if(strong_pseudo_primetest(n,23) == 0) return 0;
	if(strong_pseudo_primetest(n,29) == 0) return 0;
	if(strong_pseudo_primetest(n,31) == 0) return 0;
	if(strong_pseudo_primetest(n,37) == 0) return 0;
	return 1;
}
ll func(ll x, ll n)
{
	return (mulmod(x, x, n) + 1) % n;
}
ll pollard(ll n)
{
	ll i, x, y, p;
	if(isprime(n))
		return n;
	if(!(n & 1))
		return 2;
	for(i = 1; i < 20; i++){
		x = i;
		y = func(x, n);
		p = gcd(y - x, n);
		while(p == 1){
			x = func(x, n);
			y = func(func(y, n), n);
			p = gcd((y - x + n)%n, n) % n;
		}
		if(p == 0 || p == n)
			continue;
		return p;
	}
}
void factor(ll n)
{
	ll x;
	x = pollard(n);
	if(x == n){
		ans[ansn++] = x;
		return;
	}
	factor(x);
	factor(n/x);
}
void output(){
	int i, j;
	ll tmp;
	for(i = 0; i < ansn; i++)
		for(j = i + 1; j < ansn; j++)
			if(ans[i] > ans[j])
				std::swap(ans[i], ans[j]);
	for(int i = 0; i < ansn; i += j){
		for(j = 0; j < ansn && ans[i] == ans[i + j]; j++);
		if(i) std::cout << " *";
		//std::cout << ans[i];
		std::cout << " " << ans[i];
		if(j > 1) std::cout << "^" << j;
	}
	std::cout << std::endl;
}

int main()
{
	ll n;
	srand((unsigned)time(NULL));
	int t;
	scanf("%d", &t);
	while(t--){
		std::cin >> n;
		memset(ans, 0, sizeof(ans));
		if(isprime(n)){
			std::cout << "Prime" << std::endl;
			continue;
		}
		if(n < 0)
			break;
		ansn = 0;
		factor(n);
		std::cout << n <<" =";
		output();
	}
	return 0;
}