#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 16;
const int INF = 0x7f7f7f7f;
int N, D[MAX][MAX], DP[MAX][1 << MAX];

int solve(int visited, int cur) {
	if (visited == (1 << N) - 1) return D[cur][0] == 0 ? INF : D[cur][0];

	int &ret = DP[cur][visited];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 1; i < N; ++i) {
		if (visited & (1 << i)) continue;
		if (D[cur][i] > 0) ret = min(ret, solve(visited | (1 << i), i) + D[cur][i]);
	}

	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", &D[i][j]);
	memset(DP, -1, sizeof(DP));
	return !printf("%d\n", solve(1, 0));
}