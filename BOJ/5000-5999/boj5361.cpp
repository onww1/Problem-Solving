#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double cost[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
	int T, a;

	cout << fixed;
	cout.precision(2);

	cin >> T;
	while (T--) {
		double sum = 0.0;
		for (int i=0; i<5; ++i) {
			cin >> a;
			sum += (a * cost[i]);
		}
		cout << '$' << sum << '\n';
	}
	return 0;
}