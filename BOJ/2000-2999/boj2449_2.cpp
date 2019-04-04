#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 200;
const int INF = 0x7f7f7f7f;
int N, K, color[MAX + 1], DP[MAX + 1][MAX + 1], cnt;

int solve(int s, int e) {
	if (s == e) return 0;

	int &ret = DP[s][e];
	if (ret != -1) return ret;
	ret = INF;

	for (int k = s; k < e; ++k) {
		int offset = (color[s] == color[k + 1] ? 0 : 1);
		ret = min(ret, solve(s, k) + solve(k + 1, e) + offset);
	}

	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &K);
	for (int i = 0, prev = -1; i < N; ++i) {
		scanf("%d", color + cnt);
		if (color[cnt] != prev) prev = color[cnt++];
	}
	memset(DP, -1, sizeof(DP));
	return !printf("%d\n", solve(0, cnt - 1));
}