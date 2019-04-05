#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;
int A[MAX + 1], DP[5][5][MAX + 1], N, in;

int cost(int p1, int p2) {
	if (!p1) return 2;
	if (p1 % 4 + 1 == p2 || p1 - 1 == p2 || (p1 == 1 && p2 == 4)) return 3;
	if (abs(p1 - p2) == 2) return 4;
	if (p1 == p2) return 1;
}

int solve(int p1, int p2, int idx) {
	if (idx == N) return 0;

	int &ret = DP[p1][p2][idx];
	if (ret != -1) return ret;
	ret = INF;

	int next = A[idx];
	ret = min(ret, cost(p1, next) + solve(next, p2, idx + 1));
	ret = min(ret, cost(p2, next) + solve(p1, next, idx + 1));
	return ret;
}

int main(int argc, char *argv[]) {
	while (true) {
		scanf("%d", &in);
		if (in == 0) break;
		A[N++] = in;
	}

	memset(DP, -1, sizeof(DP));
	return !printf("%d\n", solve(0, 0, 0));
}