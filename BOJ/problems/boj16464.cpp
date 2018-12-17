#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tc, K;
	int sum[45001] = { 0, };
	for (int i=1; i<=45000; i++) {
		sum[i] = i + sum[i-1];
	}

	bool danger = true;
	cin >> tc;
	while (tc--) {
		cin >> K;
		danger = true;

		for (int i=2; i<=45000; i++) {
			if (K - sum[i] < 0) break;
			else if ((K - sum[i]) % i == 0) {
				danger = false;
				break;
			}
		}

		cout << (danger?"GoHanGang":"Gazua") << '\n';
	}
	return 0;
}