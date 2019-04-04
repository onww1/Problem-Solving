#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll mul1 = 1, mul2 = 1;
	while (b/mul1) mul1 *= 10;
	while (d/mul2) mul2 *= 10;
	cout << (a * mul1 + b + c * mul2 + d) << '\n';
	return 0;
}