#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 32000;

vector <int> edges[MAX + 1];
int n, m, in[MAX + 1], visited[MAX + 1];
int main(int argc, char *argv[]) {
	int u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		in[v]++;
	}

	queue <int> q;
	for (int i = 1; i <= n; ++i) if (!in[i]) q.push(i), visited[i] = true;
	while (!q.empty()) {
		u = q.front();
		q.pop();

		printf("%d ", u);
		for (int vv : edges[u]) {
			in[vv]--;
			if (in[vv] == 0) q.push(vv), visited[vv] = true;
		}
	}

	for (int i = 1; i <= n; ++i) if (!visited[i]) printf("%d ", i);
	return !printf("\n");
}

