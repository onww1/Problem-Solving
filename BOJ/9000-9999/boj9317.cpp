#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	double D, Rh, Rv;

	while (true) {
		cin >> D >> Rh >> Rv;
		if (!D && !Rh && !Rv) break;
		double W = (16.0 * D) / sqrt(337);
		double H = 9.0 * W / 16.0;

		cout << "Horizontal DPI: " << (Rh / W) << '\n';
		cout << "Vertical DPI: " << (Rv / H) << '\n';
	}
	return 0;
}