#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 5e4;
const int INF = 0x7f7f7f7f;

int pa[MAX + 1], ac[18][MAX + 1], depth[MAX + 1], mx[18][MAX + 1], V, E;
vector <pii> edges[MAX + 1];
priority_queue < piii, vector<piii>, greater<piii> > pq;
queue <piii> remain;

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

int _find(int a) {
	if (pa[a] < 0) return a;
	return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
	int ar = _find(a);
	int br = _find(b);
	pa[ar] = br;
}

void make_tree(int node, int parent, int dist) {
	depth[node] = depth[parent] + 1;
	ac[0][node] = parent;
	mx[0][node] = dist;
	
	for (int i = 1; i < 18; ++i) {
		int tmp = ac[i - 1][node];
		ac[i][node] = ac[i - 1][tmp];
		mx[i][node] = max(mx[i - 1][node], mx[i - 1][tmp]);
	}

	for (pii next : edges[node])
		if (next.first != parent) make_tree(next.first, node, next.second);
}

int bi_search(int u, int i, int val) {
	if (i == 0) return -1;
	int ret = -1;
	if (mx[i - 1][u] == val) ret = max(ret, bi_search(u, i - 1, val));
	else ret = max(ret, mx[i - 1][u]);
	if (mx[i - 1][ac[i - 1][u]] == val) ret = max(ret, bi_search(ac[i - 1][u], i - 1, val));
	else ret = max(ret, mx[i - 1][ac[i - 1][u]]);
	return ret;
}

int LCA(int u, int v, int val) {
	if (depth[u] < depth[v]) swap(u, v);

	int ret = -1;
	for (int i = 17; i >= 0; --i) {
		if (depth[u] - depth[v] >= (1 << i)) {
			if (mx[i][u] == val) ret = max(ret, bi_search(u, i, val));
			else ret = max(ret, mx[i][u]);
			u = ac[i][u];
		}
	}

	if (u == v) return ret;
	for (int i = 17; i >= 0; --i) {
		if (ac[i][u] != ac[i][v]) {
			if (mx[i][u] == val) ret = max(ret, bi_search(u, i, val));
			else ret = max(ret, mx[i][u]);

			if (mx[i][v] == val) ret = max(ret, bi_search(v, i, val));
			else ret = max(ret, mx[i][v]);

			u = ac[i][u];
			v = ac[i][v];
		}
	}

	if (mx[0][u] != val) ret = max(ret, mx[0][u]);
	if (mx[0][v] != val) ret = max(ret, mx[0][v]);
	return ret;
}

int main(int argc, char *argv[]) {
	int u, v, w, cnt = 0, ans = 0;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		pq.push({ w, {u, v} });
	}

	memset(pa, -1, sizeof(pa));
	while (!pq.empty()) {
		piii cur = pq.top();
		pq.pop();

		if (_find(cur.second.first) == _find(cur.second.second)) {
			remain.push(cur);
			continue;
		}
		
		ans += cur.first;
		edges[cur.second.first].push_back({ cur.second.second, cur.first });
		edges[cur.second.second].push_back({ cur.second.first, cur.first });
		_union(cur.second.first, cur.second.second);
		cnt++;

		if (cnt == V - 1) break;
	}

	if (cnt < V - 1 || E <= V - 1) {
		puts("-1");
		return 0;
	}

	while (!pq.empty()) remain.push(pq.top()), pq.pop();

	depth[0] = -1;
	make_tree(1, 0, 0);

	int diff = 0x7fffffff;
	while (!remain.empty()) {
		piii cur = remain.front();
		remain.pop();
		
		int seg_max = LCA(cur.second.first, cur.second.second, cur.first);
		if (seg_max != -1) diff = min(diff, cur.first - seg_max);
	}

	if (diff == 0x7fffffff || diff == 0) puts("-1");
	else printf("%d\n", ans + diff);

	return 0;
}

