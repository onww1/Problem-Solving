#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[1000];
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> A[i];

	int max = A[0], max_p = -1;
	int dp[1000] = {0, };
	dp[0] = A[0];
	for (int i=1; i<N; ++i) {
		max_p = 0;
		for (int j=i-1; j>=0; --j) {
			if (A[i] > A[j] && max_p < dp[j]) {
				max_p = dp[j];
			}
		}
		dp[i] = max_p + A[i];
		max = dp[i] > max ? dp[i] : max;
	}

	cout << max << '\n';

	return 0;
}