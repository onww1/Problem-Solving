#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 2e4;
const int INF = 0x7f7f7f7f;

int V, E, K, dist[MAX + 1];
vector <pii> edges[MAX + 1];
priority_queue < pii, vector<pii>, greater<pii> > pq;

int main(int argc, char *argv[]) {
	int u, v, w;
	scanf("%d %d %d", &V, &E, &K);
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back({ w, v });
	}

	memset(dist, 0x7f, sizeof(dist));
	dist[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (dist[cur.second] < cur.first) continue;

		for (pii next : edges[cur.second]) {
			if (dist[next.second] > dist[cur.second] + next.first) {
				dist[next.second] = dist[cur.second] + next.first;
				pq.push({ dist[next.second], next.second });
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}