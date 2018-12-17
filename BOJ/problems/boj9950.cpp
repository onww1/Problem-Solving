#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (!a && !b && !c) break;

		if (!a) 
			cout << (c/b) << ' ' << b << ' ' << c << '\n';
		else if (!b)
			cout << a << ' ' << (c/a) << ' ' << c << '\n';
		else if (!c)
			cout << a << ' ' << b << ' ' << (a*b) << '\n';
		else
			cout << a << ' ' << b << ' ' << c << '\n';
	}

	return 0;
}