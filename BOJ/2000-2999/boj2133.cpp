#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int dp[31] = {0, 0, 3, };
	
	if( N % 2 == 1 ) cout << 0 << '\n';
	else {
		for(int i=4; i<=N; i+=2) {
			dp[i] = 3 * dp[i-2] + 2;
			for(int j=2; j<i-2; j+=2)
				dp[i] += 2 * dp[j];
		}
		cout << dp[N] << '\n';
	}
	
	return 0;
}