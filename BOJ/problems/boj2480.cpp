#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << (10000 + a * 1000) << '\n';
	}
	else if (a == b) {
		cout << (1000 + a * 100) << '\n';
	}
	else if (a == c) {
		cout << (1000 + a * 100) << '\n';
	}
	else if (c == b) {
		cout << (1000 + b * 100) << '\n';
	}
	else {
		int max = a>b?(a>c?a:c):(b>c?b:c);
		cout << (max * 100) << '\n';
	}
	return 0;
}