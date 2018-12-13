#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);

	ll gcd_val = b;
	while (a % gcd_val) {
		b = a % gcd_val;
		a = gcd_val;
		gcd_val = b;
	}
	return gcd_val;
}

ll lcm(ll a, ll b) {
	ll gcd_val = gcd(a, b);
	return a / gcd_val * b;
}

int main(int argc, char const *argv[])
{
	ll fn, fd, sn, sd;
	cin >> fn >> fd >> sn >> sd;

	ll lcm_val = lcm(fd, sd);
	ll numerator = fn * (lcm_val / fd) + sn * (lcm_val / sd);
	ll denominator = lcm_val;
	ll gcd_val = gcd(numerator, denominator);
	cout << (numerator/gcd_val) << ' ' << (denominator/gcd_val) << '\n';

	return 0;
}