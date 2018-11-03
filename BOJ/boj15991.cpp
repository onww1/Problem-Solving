#include <iostream>
#define MOD 1000000009
using namespace std;

typedef long l;

l dp[100001] = {0, };
l sy[100001] = {0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	sy[1] = 1; sy[2] = 2; sy[3] = 2;

	for (int i=4; i<=100000; i++) {
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%MOD;

		if (i%2) {
			sy[i] = (dp[(i-1)/2] + dp[(i-3)/2])%MOD;
		}
		else {
			sy[i] = (dp[i/2] + dp[(i-2)/2])%MOD;
		}
	}

	int T, N;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		cout << sy[N] << '\n';
	}

	return 0;
}