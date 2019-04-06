#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int dp[101] = {0, 1, 1, };
	for (int i=1; i<=100; i++) {
		bool flee = true;
		for (int j=2; j<=i; j++) {
			if (i%j == 0) flee = !flee;
		}
		dp[i] = dp[i-1] + ( flee ? 1 : 0 );
	}

	int T, N;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}