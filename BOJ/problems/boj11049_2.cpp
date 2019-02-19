#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 500;
int DP[MAX + 1][MAX + 1], P[MAX + 1], N;

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	memset(DP, 0x7f, sizeof(DP));

	for (int i = 1; i <= N; ++i) {
		scanf("%d %d", &P[i - 1], &P[i]);
		DP[i][i] = 0;
	}
	
	for (int d = 1; d < N; ++d) {
		for (int i = 1; i <= N - d; ++i) {
			for (int k = i; k < i + d; ++k) {
				DP[i][i + d] = min(DP[i][i + d], DP[i][k] + DP[k + 1][i + d] + P[i - 1] * P[k] * P[i + d]);
			}
		}
	}

	return !printf("%d\n", DP[1][N]);
}