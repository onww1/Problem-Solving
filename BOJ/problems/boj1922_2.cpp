#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1e3;

vector <pii> edges[MAX + 1];
priority_queue <pii, vector<pii>, greater<pii>> pq;
int n, m, ans, visited[MAX + 1];

int main(int argc, char *argv[]) {
	int a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back({ c, b });
		edges[b].push_back({ c, a });
	}

	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (visited[v]) continue;
		visited[v] = 1;

		ans += w;
		for (pii next : edges[v]) pq.push(next);
	}

	return !printf("%d\n", ans);
}