#include <iostream>
using namespace std;

int dp[10001][2] = {0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1][0] = 1; dp[1][1] = 1;
	dp[2][0] = 2; dp[2][1] = 2;
	dp[3][0] = 2; dp[3][1] = 3;

	for (int i=4; i<=10000; i++) {
		dp[i][0] = dp[i-2][0] + 1;
		dp[i][1] = dp[i-3][1] + dp[i][0];
	}

	int T, N;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		cout << dp[N][1] << '\n';
	}

	return 0;
}