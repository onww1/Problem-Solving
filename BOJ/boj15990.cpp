#include <iostream>
#define MOD 1000000009
using namespace std;

typedef long l;

l dp[100001][3] = {0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 0;
	dp[2][0] = 0; dp[2][1] = 1; dp[2][2] = 0;
	dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;

	for (int i=4; i<=100000; i++) {
		dp[i][0] = (dp[i-1][1] + dp[i-1][2])%MOD;
		dp[i][1] = (dp[i-2][0] + dp[i-2][2])%MOD;
		dp[i][2] = (dp[i-3][0] + dp[i-3][1])%MOD;
	}

	int T, N;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		cout << (dp[N][0] + dp[N][1] + dp[N][2])%MOD << '\n';
	}

	return 0;
}