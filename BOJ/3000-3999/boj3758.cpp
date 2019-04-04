#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
	int score[101];
	int s, n, t, i;
};

bool cmp(node a, node b) {
	if (a.s == b.s && a.n == b.n) return a.t < b.t;
	if (a.s == b.s) return a.n < b.n;
	return a.s > b.s;
}

int T, n, k, t, m;
node A[101];
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(A, 0, sizeof(A));
		scanf("%d %d %d %d", &n, &k, &t, &m);
		for (int i = 1; i <= n; ++i) A[i].i = i;
		for (int r = 0, i, j, s; r < m; ++r) {
			scanf("%d %d %d", &i, &j, &s);
			A[i].score[j] = max(A[i].score[j], s);
			A[i].t = r;
			A[i].n++;
		}
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= k; ++j) A[i].s += A[i].score[j];
		sort(A + 1, A + n + 1, cmp);
		for (int i = 1; i <= n; ++i) if (A[i].i == t) {
			printf("%d\n", i);
			break;
		}
	}
}