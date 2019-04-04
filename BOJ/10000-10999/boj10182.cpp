#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string type;
	char dummy;
	double val;

	cout << fixed;
	cout.precision(2);

	while (N--) {
		cin >> type >> dummy >> val;
		double ph = 0.0 - log10(val);
		if (type.compare("H") == 0) {
			cout << ph << '\n';
		}
		else {
			cout << (14.0 - ph) << '\n';
		}
	}
	return 0;
}