#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;

int main(int argc, char const *argv[])
{
	ull dp[251][6] = {0LL, };
	dp[1][0] = 1LL; dp[2][0] = 3LL;

	for (int i=3; i<=250; i++) {
		for (int j=0; j<6; j++) {
			dp[i][j] += dp[i-1][j] + 2 * dp[i-2][j];
			if (j < 5) {
				if (dp[i][j] / (10000000000000000LL)) {
					dp[i][j+1] += dp[i][j] / (10000000000000000LL);
					dp[i][j] %= (10000000000000000LL);
				}
			}
		}
	}
	
	int N;
	while (~scanf("%d", &N)) {
		if (N == 0) {
			cout << 1 << '\n';
			continue;
		}
		bool head = false;
		for (int j=5; j>=0; j--) {
			if (!head && dp[N][j]) {
				cout << dp[N][j];
				head = true;
			}
			else if (head) {
				for (ull d = 1000000000000000LL; d >= 0; d/=10LL) {
					if (!(dp[N][j] / d)) cout << 0;
					else {
						cout << dp[N][j];
						break;
					}
				}
			}
		}
		cout << '\n';
	}

	return 0;
}