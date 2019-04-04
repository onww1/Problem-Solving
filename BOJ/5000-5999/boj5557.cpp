#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[100];
	ll dp[100][21] = {0, };

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	dp[0][A[0]] = 1LL;
	for (int i=1; i<N-1; i++) {
		for (int j=0; j<=20; j++) {
			if ( 0 <= j + A[i] && j + A[i] <= 20 )
				dp[i][j+A[i]] += dp[i-1][j];
			if ( 0 <= j - A[i] && j - A[i] <= 20 )
				dp[i][j-A[i]] += dp[i-1][j];
		}
	}

	cout << dp[N-2][A[N-1]] << '\n';

	return 0;
}