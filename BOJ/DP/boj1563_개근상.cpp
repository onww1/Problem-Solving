#include <iostream>
#define MOD 1000000
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	int dp[1000][2][3] = {0, };
	dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;
	for (int i=1; i<N; i++) {
		dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2])%MOD;
		dp[i][0][1] = dp[i-1][0][0]%MOD;
		dp[i][0][2] = dp[i-1][0][1]%MOD;
		dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
					 + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2])%MOD;
		dp[i][1][1] = dp[i-1][1][0]%MOD;
		dp[i][1][2] = dp[i-1][1][1]%MOD;
	}
	int res = (dp[N-1][0][0] + dp[N-1][0][1] + dp[N-1][0][2]
			 + dp[N-1][1][0] + dp[N-1][1][1] + dp[N-1][1][2])%MOD;

	cout << res << '\n';
	return 0;
}