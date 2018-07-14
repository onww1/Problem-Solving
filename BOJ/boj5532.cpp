#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	a = a/c + (a%c?1:0);
	b = b/d + (b%d?1:0);

	cout << ((a>b)?l-a:l-b) << '\n';
	return 0;
}