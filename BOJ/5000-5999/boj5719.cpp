#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 500;
const int INF = 0x7f7f7f7f;
int N, M, S, D, dist[MAX], rmv[MAX][MAX], visited[MAX];
vector <int> pv[MAX + 1];
vector <pii> edges[MAX + 1];

void dijkstra() {
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	dist[S] = 0; pq.push({ 0, S });

	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (dist[cur.second] < cur.first) continue;
		for (pii next : edges[cur.second]) {
			if (rmv[cur.second][next.first]) continue;

			if (dist[next.first] > dist[cur.second] + next.second) {
				dist[next.first] = dist[cur.second] + next.second;
				pq.push({ dist[next.first], next.first });
				pv[next.first].clear();  
				pv[next.first].push_back(cur.second);
			}
			else if (dist[next.first] == dist[cur.second] + next.second) 
				pv[next.first].push_back(cur.second);
		}
	}
}

void remove_min(int cur) {
	visited[cur] = 1;
	for (int pre : pv[cur]) {
		rmv[pre][cur] = 1;
		if (!visited[pre]) remove_min(pre);
	}
}

int main(int argc, char *argv[]) {
	int u, v, p;
	
	while (true) {
		scanf("%d %d", &N, &M);
		if (!N && !M) break;
		scanf("%d %d", &S, &D);
		
		memset(rmv, 0, sizeof(rmv));
		memset(dist, 0x7f, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; ++i) {
			edges[i].clear();
			pv[i].clear();
		}

		for (int i = 0; i < M; ++i) {
			scanf("%d %d %d", &u, &v, &p);
			edges[u].push_back({ v, p });
		}

		dijkstra();
		int mn = dist[D];
		remove_min(D);

		memset(dist, 0x7f, sizeof(dist));
		dijkstra();
		printf("%d\n", dist[D] == INF || dist[D] == mn ? -1 : dist[D]);
	}
	
	return 0;
}

