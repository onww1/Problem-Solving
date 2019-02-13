#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int order[MAX + 1], visited[MAX + 1], V, E, cnt, src, od;
bool is_cut[MAX + 1];
vector <int> edges[MAX + 1];

int dfs(int node) {
	int low = ++od, scnt = 0;
	order[node] = od;
	visited[node] = true;

	for (int next : edges[node]) {
		if (!visited[next]) {
			if (node == src) ++scnt;
			int val = dfs(next);
			if (!is_cut[node] && val == order[node]) {
				is_cut[node] = true;
				if (node != src) ++cnt;
			}
			low = min(low, val);
		}
		else low = min(low, order[next]);
	}

	if (node == src) {
		if (is_cut[node] && scnt > 1) ++cnt;
		else is_cut[node] = false;
	}

	return low;
}

int main(int argc, char *argv[]) {
	int u, v;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 1; i <= V; ++i)
		if (!visited[i]) {
			src = i;
			dfs(i);
		}

	printf("%d\n", cnt);
	for (int i = 1; i <= V; ++i)
		if (is_cut[i]) printf("%d ", i);
	return !printf("\n");
}