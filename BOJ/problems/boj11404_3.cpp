#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100;
const int INF = 0x7f7f7f7f;

int N, M, dist[MAX + 1];
vector <pii> edges[MAX + 1];

void dijkstra(int src) {
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	dist[src] = 0; pq.push({ 0, src });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = pq.top().first;
		pq.pop();

		for (auto &next : edges[cur]) {
			if (dist[next.first] > dist[cur] + next.second) {
				dist[next.first] = dist[cur] + next.second;
				pq.push({ dist[next.first], next.first });
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int u, v, w;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back({ v, w });
	}

	for (int i = 1; i <= N; ++i) {
		memset(dist, 0x7f, sizeof(dist));
		dijkstra(i);
		for (int j = 1; j <= N; ++j) printf("%d ", dist[j] == INF ? 0 : dist[j]);
		puts("");
	}

	return 0;
}