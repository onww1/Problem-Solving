#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(5);

	int pedometer, N, walks, user = 0;
	double res;

	while (1) {
		cin >> pedometer;
		if (!pedometer) break;

		cin >> N;
		cout << "User " << ++user << '\n';
		for (int i=0; i<N; ++i) {
			cin >> walks;
			cout << ((pedometer * walks) / 100000.0) << '\n';
		}
	}
	return 0;
}