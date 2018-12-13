#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char c; int s;
	cin >> c;
	if (c == 'F') cout << "0.0" << '\n';
	else {
		s = 4 - (c - 'A');
		cin >> c;
		if (c == '-') s--;
		cout << s << '.';
		if (c =='+') cout << 3 << '\n';
		if (c =='0') cout << 0 << '\n';
		if (c =='-') cout << 7 << '\n';
	}
	return 0;
}