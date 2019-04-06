#include <iostream>
using namespace std;

int my_min(int a, int b) { return a < b ? a : b; }

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int file[501][501] = {0, };
	int dp[501][501] = {0, };
	int T, N;
	cin >> T;

	while( T-- ) {
		cin >> N;
		for (int i=1; i<=N; i++) {
			cin >> file[i][i];
		}

		for (int width=1; width<N; width++) {
			for (int i=1; i<=N-width; i++) {
				file[i][i+width] = file[i][i] + file[i+1][i+width];
			}
		}

		for (int width=1; width<N; width++) {
			for (int i=1; i<=N-width; i++) {
				dp[i][i+width] = dp[i][i] + dp[i+1][i+width];
				for (int k=i+1; k<i+width; k++) {
					dp[i][i+width] = my_min(dp[i][i+width], dp[i][k] + dp[k+1][i+width]);
				}
				dp[i][i+width] += file[i][i+width];
			}
		}

		cout << dp[1][N] << '\n';
	}

	return 0;
}
