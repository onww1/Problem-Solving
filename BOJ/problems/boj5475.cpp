#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
int N, DP[MAX + 1][4][4][4][4];
char in[MAX + 1];

int parse(char c) {
	if (c == 'M') return 1;
	else if (c == 'F') return 2;
	return 3;
}

int coal(int pp, int p, int cur) {
	if (!p) return 1;
	else if (!pp) return (p != cur ? 2 : 1);
	else {
		if (pp == p && p == cur) return 1;
		else if (pp != p && p != cur && cur != pp) return 3;
		return 2;
	}
}

int solve(int T, int pp1, int p1, int pp2, int p2) {
	if (T == N) return 0;

	int &ret = DP[T][pp1][p1][pp2][p2];
	if (ret != -1) return ret;
	ret = 0;

	int cur = parse(in[T]);
	ret = max(ret, coal(pp1, p1, cur) + solve(T + 1, p1, cur, pp2, p2));
	ret = max(ret, coal(pp2, p2, cur) + solve(T + 1, pp1, p1, p2, cur));
	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d %s", &N, in);
	memset(DP, -1, sizeof(DP));
	return !printf("%d\n", solve(0, 0, 0, 0, 0));
}