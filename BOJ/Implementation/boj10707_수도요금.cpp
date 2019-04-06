#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int X = a * p;
	int Y = b + ((p>c)?((p-c)*d):0);

	cout << ((X>Y)?Y:X) << '\n';
	return 0;
}