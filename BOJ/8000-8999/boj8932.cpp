#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double A[] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
	double B[] = {26.7, 75.0, 1.5, 42.5, 210.0, 3.8, 254.0};
	double C[] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
	bool F[] = {false, true, true, false, true, true, false};

	int T;
	cin >> T;

	ll sum = 0LL;
	double P;
	while (T--) {
		sum = 0LL;
		for (int i=0; i<7; ++i) {
			cin >> P;
			if (F[i]) P = P - B[i];
			else P = B[i] - P;
			P = pow(P, C[i]);
			sum += (ll)(A[i] * P);
		}
		cout << sum << '\n';
	}

	return 0;
}