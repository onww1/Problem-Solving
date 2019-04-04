#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1e5;
int V, E, order[MAX + 1], od;
bool visited[MAX + 1];
vector <int> edges[MAX + 1];
vector <pii> ans;

int dfs(int node, int parent) {
	order[node] = ++od;
	int low = od;
	visited[node] = true;

	for (int next : edges[node]) {
		if (next != parent) {
			if (!visited[next]) {
				int val = dfs(next, node);
				if (val > order[node]) ans.push_back({ min(next,node), max(next,node) });
				low = min(low, val);
			}
			else low = min(low, order[next]);
		}
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
		if (!visited[i]) dfs(i, 0);

	sort(ans.begin(), ans.end());
	printf("%lu\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}