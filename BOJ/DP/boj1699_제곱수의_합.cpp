#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, dp[100001] = {0, };
	cin >> N;

	for (int i=0; i<=N; i++)
		dp[i] = i;

	for (int i=1; i<=N; i++) {
		for (int j=1; j * j <= i; j++) {
			dp[i] = ( dp[i - j*j] + 1 < dp[i] ? dp[i - j*j] + 1 : dp[i] );
		}
	}

	cout << dp[N] << '\n';

	return 0;
}