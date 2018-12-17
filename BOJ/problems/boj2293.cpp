#include <iostream>
using namespace std;

int main() {
	int N, K, x, i, j;
	int dp[10001] = { 1, };
	cin >> N >> K;
	for (i = 1; i <= N; i++) {
		cin >> x;
		for (j = 0; j <= K - x; j++)
			dp[j + x] += dp[j];
	}
	cout << dp[K] << '\n';
	return 0;
}