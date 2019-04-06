#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100;
const int MOD = 100000;
int DP[MAX + 1][MAX + 1][2], w, h;

int solve(int x, int y, int up) {
	if ((x == 0 && y <= 0) || (x <= 0 && y == 0)) return 1;
	if (x < 0 || y < 0) return 0;
	
	int &ret = DP[x][y][up];
	if (ret != -1) return ret;
	ret = 0;

	if (up) {
		ret += solve(x, y - 1, up);
		ret += solve(x - 2, y, 1 - up);
		ret %= MOD;
	}
	else {
		ret += solve(x - 1, y, up);
		ret += solve(x, y - 2, 1 - up);
		ret %= MOD;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d %d", &w, &h);
	memset(DP, -1, sizeof(DP));
	return !printf("%d\n", (solve(w - 1, h - 3, 1) + solve(w - 2, h - 3, 1) +
							solve(w - 3, h - 2, 0) + solve(w - 3, h - 1, 0)) % MOD);
}

