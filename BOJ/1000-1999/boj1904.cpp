#include <iostream>
#define MOD 15746
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int dp[1000001] = {0, };
	dp[0] = 1; dp[1] = 1;

	for (int i=2; i<=N; i++) {
		dp[i] = (dp[i-1] + dp[i-2])%MOD;
	}

	cout << dp[N] << '\n';

	return 0;
}