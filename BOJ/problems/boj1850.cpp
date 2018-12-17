#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ull a, b;
	cin >> a >> b;

	if (a < b) {
		ull temp = a;
		a = b;
		b = temp;
	}

	string str(5000, '1');

	ull gcd = b;
	while (a % gcd) {
		b = a % gcd;
		a = gcd;
		gcd = b;
	}

	while (gcd > 5000) {
		cout << str;
		gcd -= 5000;
	}
	cout << str.substr(0, gcd) << '\n';

	return 0;
}