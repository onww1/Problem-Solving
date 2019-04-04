#include <cstdio>
#include <algorithm>
using namespace std;

int DP[3][2][2], in[3];
int main(int argc, char *argv[]) {
	int n, i, j, k;
	scanf("%d", &n);

	for (j = 0; j < 3; ++j) {
		scanf("%d", &DP[j][0][0]);
		DP[j][1][0] = DP[j][0][0];
	}

	for (i = 1; i < n; ++i) {
		for (j = 0; j < 3; ++j) scanf("%d", in + j);
		DP[0][0][1] = min({ DP[0][0][0], DP[1][0][0] }) + in[0];
		DP[1][0][1] = min({ DP[0][0][0], DP[1][0][0], DP[2][0][0] }) + in[1];
		DP[2][0][1] = min({ DP[1][0][0], DP[2][0][0] }) + in[2];
		
		DP[0][1][1] = max({ DP[0][1][0], DP[1][1][0] }) + in[0];
		DP[1][1][1] = max({ DP[0][1][0], DP[1][1][0], DP[2][1][0] }) + in[1];
		DP[2][1][1] = max({ DP[1][1][0], DP[2][1][0] }) + in[2];
		for (j = 0; j < 3; ++j) for (k = 0; k < 2; ++k) DP[j][k][0] = DP[j][k][1];
	}

	int mx = 0, mn = 1e9;
	for (i = 0; i < 3; ++i) {
		mx = max(mx, DP[i][1][0]);
		mn = min(mn, DP[i][0][0]);
	}
	return !printf("%d %d\n", mx, mn);
}

