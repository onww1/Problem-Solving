#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e4;
const int MOD = 1e9 + 7;
const int INF = 0x7f7f7f7f;
int N, H[MAX + 1], DP[2][5001];

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	bool valid = true;
	for (int i = 0; i < N; ++i) {
		scanf("%d", H + i);
		if (H[i] >(N - 1) / 2) valid = false;
	}

	if (!valid) return !printf("0\n");

	DP[0][0] = 1; H[N - 1] = 0;
	for (int i = 1; i < N; ++i) {
		if (H[i] == -1) {
			for (int j = 0; j <= 5000; ++j) {
				if (j < 5000) DP[1][j] = (DP[1][j] + DP[0][j + 1]) % MOD;
				DP[1][j] = (DP[1][j] + DP[0][j]) % MOD;
				if (j) DP[1][j] = (DP[1][j] + DP[0][j - 1]) % MOD;
			}
		}
		else {
			if (H[i] < 5000) DP[1][H[i]] = (DP[1][H[i]] + DP[0][H[i] + 1]) % MOD;
			DP[1][H[i]] = (DP[1][H[i]] + DP[0][H[i]]) % MOD;
			if (H[i]) DP[1][H[i]] = (DP[1][H[i]] + DP[0][H[i] - 1]) % MOD;
		}

		for (int j = 0; j <= 5000; ++j) DP[0][j] = DP[1][j], DP[1][j] = 0;
	}

	return !printf("%d\n", DP[0][0]);
}