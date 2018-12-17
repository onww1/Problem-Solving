#include <iostream>
#include <cstring>
#define INF 0b0111'1111'0111'1111'0111'1111'0111'1111
using namespace std;

int getMin(int a, int b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, r, c;
	cin >> N;

	int dp[501][501] = {0, };
	int p[501] = {0, };

	memset(dp, 127, sizeof(int) * 501 * (N+1));
	for (int i=1; i<=N; i++) dp[i][i] = 0;

	cin >> p[0];
	for (int i=1; i<N; i++) {
		cin >> p[i] >> p[i];
	}
	cin >> p[N];

	for (int i=1; i<N; i++) {
		for (int j=1; j<=N-i; j++) {
			for (int k=j; k<j+i; k++) {
				dp[j][j+i] = getMin(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + p[j-1] * p[k] * p[j+i]);
			}
		}
	}

	cout << dp[1][N] << '\n';
	return 0;
}