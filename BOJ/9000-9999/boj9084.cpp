#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int dp[10001] = {1, };
	int T, N, A, M;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(int) * 10001);
		dp[0] = 1;

		cin >> N;
		for (int i=0; i<N; ++i) {
			cin >> A;
			for (int j=0; j + A <= 10000; j++)
				dp[j+A] += dp[j];
		}

		cin >> M;
		cout << dp[M] << '\n';
	}
	return 0;
}