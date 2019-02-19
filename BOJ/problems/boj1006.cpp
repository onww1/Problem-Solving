#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000;
const int INF = 0x3f3f3f3f;
int T, N, W, A[2][MAX + 1], DP[2][MAX + 2];

int solve(int pos, int type) {
	if (pos == N) return 0;
	
	int &ret = DP[type][pos];
	if (ret != -1) return ret;
	ret = INF;

	if (!type) {
		if (A[0][pos] + A[1][pos] <= W) ret = min(ret, 1 + solve(pos + 1, 0));
		if (pos < N - 1 && A[0][pos] + A[0][pos + 1] <= W) {
			if (A[1][pos] + A[1][pos + 1] <= W) ret = min(ret, 2 + solve(pos + 2, 0));
			else ret = min(ret, 2 + solve(pos + 1, 1));
		}
		ret = min(ret, 1 + solve(pos, 1));
	}
	else {
		if (pos < N - 1 && A[1][pos] + A[1][pos + 1] <= W) {
			if (pos < N - 2 && A[0][pos + 1] + A[0][pos + 2] <= W) ret = min(ret, 2 + solve(pos + 2, 1));
			else ret = min(ret, 2 + solve(pos + 2, 0));
		}
		ret = min(ret, 1 + solve(pos + 1, 0));
	}

	return ret;
}

int main(int argc, char *argv[]) {
	for (scanf("%d", &T); T; T--) {
		scanf("%d %d", &N, &W);
		for (int i = 0; i < 2; ++i) for (int j = 0; j < N; ++j) scanf("%d", &A[i][j]);

		int mn = INF;
		if (N > 1 && A[0][0] + A[0][N - 1] <= W && A[1][0] + A[1][N - 1] <= W) {
			memset(DP, -1, sizeof(DP));
			int tmp[4] = { A[0][0], A[1][0], A[0][N - 1], A[1][N - 1] };
			A[0][0] = A[1][0] = A[0][N - 1] = A[1][N - 1] = INF;
			mn = min(mn, solve(0, 0) - 2);
			A[0][0] = tmp[0], A[1][0] = tmp[1], A[0][N - 1] = tmp[2], A[1][N - 1] = tmp[3];
		}

		if (N > 1 && A[0][0] + A[0][N - 1] <= W) {
			memset(DP, -1, sizeof(DP));
			int tmp[2] = { A[0][0], A[0][N - 1] };
			A[0][0] = A[0][N - 1] = INF;
			mn = min(mn, solve(0, 0) - 1);
			A[0][0] = tmp[0], A[0][N - 1] = tmp[1];
		}
		if (N > 1 && A[1][0] + A[1][N - 1] <= W) {
			memset(DP, -1, sizeof(DP));
			int tmp[2] = { A[1][0], A[1][N - 1] };
			A[1][0] = A[1][N - 1] = INF;
			mn = min(mn, solve(0, 0) - 1);
			A[1][0] = tmp[0], A[1][N - 1] = tmp[1];
		}
		
		memset(DP, -1, sizeof(DP));
		mn = min(mn, solve(0, 0));

		printf("%d\n", mn);
	}
	return 0;
}