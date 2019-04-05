#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1000;
const int INF = 0x7f7f7f7f;
int N, W, DP[MAX + 1][MAX + 1];
pii T[MAX + 1], T1, T2;

int dist(pii &a, pii &b) { return abs(a.first - b.first) + abs(a.second - b.second); }

int solve(int t1, int t2) {
	if (t1 == W || t2 == W) return 0;

	int &ret = DP[t1][t2];
	if (ret != -1) return ret;
	ret = INF;

	int next = max(t1, t2) + 1;
	ret = min(ret, solve(next, t2) + dist(T[next], t1 ? T[t1] : T1));
	ret = min(ret, solve(t1, next) + dist(T[next], t2 ? T[t2] : T2));
	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &W);
	T1 = { 1, 1 }, T2 = { N, N };
	for (int i = 1; i <= W; ++i) scanf("%d %d", &T[i].first, &T[i].second);
	memset(DP, -1, sizeof(DP));
	printf("%d\n", solve(0, 0));

	for (int i = 1, t1 = 0, t2 = 0; i <= W; ++i) {
		if (dist(T1, T[i]) == (i < W ? DP[t1][t2] - DP[i][t2] : DP[t1][t2])) {
			puts("1");
			T1 = T[i];
			t1 = i;
		}
		else {
			puts("2");
			T2 = T[i];
			t2 = i;
		}
	}
	return 0;
}