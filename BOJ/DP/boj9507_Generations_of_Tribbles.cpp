#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;

	ll F[68] = {0, };
	F[0] = F[1] = 1; F[2] = 2; F[3] = 4;
	for (int i=4; i<68; ++i) {
		F[i] = F[i-1] + F[i-2] + F[i-3] + F[i-4];
	}

	while (T--) {
		cin >> N;
		cout << F[N] << '\n';
	}
	return 0;
}