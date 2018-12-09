#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll C, K, P;
	cin >> C >> K >> P;

	ll f = K * (C * (C+1)) / 2;
	ll s = P * (C * (C+1) * (2*C + 1)) / 6;

	cout << (f + s) << '\n';
	return 0;
}