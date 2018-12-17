#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	int gcd = b;
	while (a % gcd != 0) {
		b = a % gcd;
		a = gcd;
		gcd = b;
	}
	return gcd;
}

int main() {
	int A, B;
	cin >> A >> B;

	int GCD = gcd(B-A, A);
	cout << ((B-A)/GCD) << ' ' << (B/GCD) << '\n';

	return 0;
}