#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;

vector <pii> edges[MAX + 1];
int ac[MAX + 1][21], mn[MAX + 1][21], mx[MAX + 1][21];
int n, k, depth[MAX + 1];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

void make_tree(int node, int parent, int dist) {
	depth[node] = depth[parent] + 1;

	ac[node][0] = parent;
	mn[node][0] = mx[node][0] = dist;

	for (int i = 1; i < 21; ++i) {
		int tmp = ac[node][i - 1];
		ac[node][i] = ac[tmp][i - 1];
		mn[node][i] = min(mn[node][i - 1], mn[tmp][i - 1]);
		mx[node][i] = max(mx[node][i - 1], mx[tmp][i - 1]);
	}

	for (pii edge : edges[node])
		if (edge.first != parent) make_tree(edge.first, node, edge.second);
}

int main(int argc, char *argv[]) {
	int u, v, w, i;
	scanf("%d", &n);

	for (i = 1; i < n; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back({ v, w });
		edges[v].push_back({ u, w });
	}

	depth[0] = -1;
	make_tree(1, 0, 0);

	scanf("%d", &k);
	int min_val, max_val;
	while (k--) {
		min_val = INF, max_val = -INF;
		scanf("%d %d", &u, &v);
		if (depth[u] < depth[v]) swap(u, v);

		for (i = 20; i >= 0; --i)
			if (depth[u] - depth[v] >= (1 << i)) {
				min_val = min(min_val, mn[u][i]);
				max_val = max(max_val, mx[u][i]);
				u = ac[u][i];
			}

		if (u == v) {
			printf("%d %d\n", min_val, max_val);
			continue;
		}

		for (i = 20; i >= 0; --i) {
			if (ac[u][i] != ac[v][i]) {
				min_val = min({ min_val, mn[u][i], mn[v][i]});
				max_val = max({ max_val, mx[u][i], mx[v][i]});
				u = ac[u][i], v = ac[v][i];
			}
		}

		min_val = min({ min_val, mn[u][0], mn[v][0] });
		max_val = max({ max_val, mx[u][0], mx[v][0] });
		printf("%d %d\n", min_val, max_val);
	}

	return 0;
}

