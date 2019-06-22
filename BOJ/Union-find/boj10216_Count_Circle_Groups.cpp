#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct info {
	int x, y, r;
} infos[3001];
int t, n, ans, pa[3001];

int _find(int u) {
	if (pa[u] < 0) return u;
	return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
	int up = _find(u);
	int vp = _find(v);
	if (up != vp) {
		pa[up] = vp;
		ans--;
	}
}

int main(int argc, char *argv[]) {
    scanf("%d", &t);
    while (t--) {
    	scanf("%d", &n);
    	memset(pa, -1, sizeof(pa)); ans = n;
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d %d %d", &infos[i].x, &infos[i].y, &infos[i].r);
    		for (int j = 1; j < i; ++j) {
    			int dist = (infos[i].x - infos[j].x) * (infos[i].x - infos[j].x) + (infos[i].y - infos[j].y) * (infos[i].y - infos[j].y);
    			int rsq = (infos[i].r + infos[j].r) * (infos[i].r + infos[j].r);
    			if (dist <= rsq) _union(i, j);
    		}
    	}
    	printf("%d\n", ans);
    }
    return 0;
}