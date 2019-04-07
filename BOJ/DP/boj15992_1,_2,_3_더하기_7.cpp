#include <iostream>
#define MOD 1000000009
using namespace std;

typedef long l;

l dp[1001][1001] = {0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1][1] = 1;
	dp[2][1] = 1; dp[2][2] = 1;
	dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;

	for (int i=4; i<=1000; i++) {
		for (int j=i/3; j<=i; j++) {
			dp[i][j] = ((long)dp[i-1][j-1] + (long)dp[i-2][j-1] + (long)dp[i-3][j-1])%MOD;
		}
	}

	int T, N, M;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N >> M;
		cout << dp[N][M] << '\n';
	}

	return 0;
}