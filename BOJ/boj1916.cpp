#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

struct edge {
	int v, w;
};

bool operator<(edge a, edge b) {
	return a.w > b.w;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, src, dst;
	cin >> N >> M;

	vector< vector<edge> > edges(N);
	vector<bool> visited(N, false);
	vector<int> dist(N, INF);

	int u, v, w;
	for (int i=0; i<M; ++i) {
		cin >> u >> v >> w;
		edges[u-1].push_back({v-1, w});
	}

	cin >> src >> dst;
	src--; dst--;

	priority_queue<edge> pq;
	dist[src] = 0;
	visited[src] = true;
	int len = edges[src].size();
	for (int i=0; i<len; ++i) {
		if (dist[edges[src][i].v] > dist[src] + edges[src][i].w) {
			dist[edges[src][i].v] = dist[src] + edges[src][i].w;
			pq.push({edges[src][i].v, dist[edges[src][i].v]});
		}
	}

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		if (visited[e.v]) continue;
		if (e.v == dst) {
			cout << e.w << '\n';
			break;
		}

		len = edges[e.v].size();
		for (int i=0; i<len; ++i) {
			if (dist[edges[e.v][i].v] > dist[e.v] + edges[e.v][i].w) {
				dist[edges[e.v][i].v] = dist[e.v] + edges[e.v][i].w;
				pq.push({edges[e.v][i].v, dist[edges[e.v][i].v]});
			}
		}
	}

	return 0;
}
