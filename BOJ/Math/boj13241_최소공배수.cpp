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
	ll a, b;
	cin >> a >> b;
	cout << lcm(a, b) << '\n';
	return 0;
}