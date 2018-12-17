#include <iostream>
#define MOD 1000000009
using namespace std;

typedef long l;

l dp[1000001] = {0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1] = 1L;
	dp[2] = 2L;
	dp[3] = 4L;

	for (int i=4; i<=1000000; i++) {
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
	}

	int T, N;
	cin >> T;

	for (int i=0; i<T; i++) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}