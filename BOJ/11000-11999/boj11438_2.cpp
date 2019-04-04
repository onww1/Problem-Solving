#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
int depth[MAX + 1], ac[MAX + 1][20], n, m, max_lvl;
vector <int> edges[MAX + 1];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

void make_tree(int node, int parent) {
	depth[node] = depth[parent] + 1;
	ac[node][0] = parent;
	
	for (int i = 1; i <= max_lvl; ++i) {
		int tmp = ac[node][i - 1];
		ac[node][i] = ac[tmp][i - 1];
	}

	for (int next : edges[node])
		if (next != parent) make_tree(next, node);
}

int main(int argc, char *argv[]) {
	int u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	max_lvl = (int)floor(log2(MAX + 1));
	depth[0] = -1;
	make_tree(1, 0);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		if (depth[u] < depth[v]) swap(u, v);
		while (depth[u] > depth[v]) {
			for (int i = 1; i < 31; ++i)
				if (depth[u] - depth[v] < (1 << i)) {
					u = ac[u][i - 1];
					break;
				}
		}

		int anc = (u == v ? u : 0);
		while (!anc) {
			for (int i = 0; i < 20; ++i) {
				if (ac[u][i] == ac[v][i]) {
					if (i == 0) anc = ac[u][0];
					else u = ac[u][i - 1], v = ac[v][i - 1];
					break;
				}
			}
		}
		printf("%d\n", anc);
	}
	return 0;
}