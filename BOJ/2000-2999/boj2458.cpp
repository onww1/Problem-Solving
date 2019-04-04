#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 500;
bool edges[MAX + 1][MAX + 1];
int n, m, cnt[MAX + 1];

int main(int argc, char *argv[]) {
	int a, b, i, j, k;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		edges[a][b] = 1;
	}

	for (k = 1; k <= n; ++k) 
		for (i = 1; i <= n; ++i) 
			for (j = 1; j <= n; ++j) 
				edges[i][j] |= (edges[i][k] && edges[k][j]);
	
	int count = 0;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (edges[i][j]) cnt[j]++, cnt[i]++;
		}
	}

	for (i = 1; i <= n; ++i) if (cnt[i] == n - 1) ++count;

	return !printf("%d\n", count);
}