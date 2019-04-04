#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;

const int MAX = 200;
int comb[MAX + 1][MAX + 1];
int n, m, k, p;
char ans[MAX + 1];

void init() {
	for (int i = 0; i <= MAX; ++i) comb[i][0] = comb[i][i] = 1;
	for (int i = 2; i <= MAX; ++i) for (int j = 1; j < i; ++j) {
		if (comb[i - 1][j] == -1 || comb[i - 1][j - 1] == -1 || comb[i - 1][j] + comb[i - 1][j - 1] >= 1e9) comb[i][j] = -1;
		else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	}
}

int main(int argc, char *argv[]) {
	init();
	scanf("%d %d %d", &n, &m, &k);
	if (comb[n + m][m] != -1 && comb[n + m][m] < k) return !printf("-1\n");

	--k;
	while (k && n && m) {
		if (comb[n + m - 1][m] == -1 || comb[n + m - 1][m] > k) ans[p++] = 'a', --n;
		else ans[p++] = 'z', k -= comb[n + m - 1][m], --m;
	}
	while (n--) ans[p++] = 'a';
	while (m--) ans[p++] = 'z';
	ans[p] = 0;
	return !printf("%s\n", ans);
}

