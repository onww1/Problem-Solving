#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K, V[101] = { 0, }, dp[10001] = { 0, };

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
		int step = 1;
		for(int j = 1; j <= K; j += step) {
			if( j % V[i] == 0 ) {
				int tmp = j / V[i];
				if( dp[j] != 0 && dp[j] < tmp ) break;
				dp[j] = tmp;
				step = V[i];
			}
		}
	}

	sort(V, V+N);

	for(int i=1; i<=K; i++)
		cout << i << "\t" << dp[i] << '\n';
	
	return 0;
}