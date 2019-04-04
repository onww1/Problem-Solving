#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct edge {
	int u, v, w;
};

bool operator<(edge a, edge b) {
	return a.w > b.w;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector< vector<int> > edges(N, vector<int>(N, INF));
	vector<bool> visited(N, false);
	priority_queue<edge> pq;

	int u, v, w;
	for (int i=0; i<M; ++i) {
		cin >> u >> v >> w;
		edges[u-1][v-1] = edges[v-1][u-1] = w;
	}

	int cnt = 1;
	visited[0] = true;
	for (int i=1; i<N; ++i) {
		if (edges[0][i] < INF) 
			pq.push({0, i, edges[0][i]});
	}

	int cost = 0;
	while (!pq.empty() && cnt < N) {
		edge e = pq.top();
		pq.pop();

		if (visited[e.v]) continue;
		visited[e.v] = true;
		cost += e.w;
		cnt++;

		for (int i=0; i<N; ++i) {
			if (!visited[i] && edges[e.v][i] < INF) {
				pq.push({e.v, i, edges[e.v][i]});
			}
		}
	}

	cout << cost << '\n';

	return 0;
}