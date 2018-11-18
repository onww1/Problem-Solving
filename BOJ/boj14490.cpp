#include <iostream>
#include <string>
using namespace std;

int cal_gcd(int a, int b) {
	int gcd = b;
	while (a % gcd) {
		b = a % gcd;
		a = gcd;
		gcd = b;
	}
	return gcd;
}

int main() {
	string input;
	cin >> input;

	int a = 0, b = 0;
	int i = 0, len = input.length();
	while (input[i] != ':') {
		a = (a * 10) + input[i] - '0';
		i++;
	}
	i++;
	while (i < len) {
		b = (b * 10) + input[i] - '0';
		i++;
	}

	int gcd = cal_gcd(a, b);
	cout << (a/gcd) << ':' << (b/gcd) << '\n';
	return 0;
}