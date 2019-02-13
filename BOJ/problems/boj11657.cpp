#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int MAX = 500;
const int INF = 0x7f7f7f7f;

int N, M, dist[MAX + 1];
vector <piii> edges;

int main(int argc, char *argv[]) {
	int u, v, w;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back({ {u,v},w });
	}

	memset(dist, 0x7f, sizeof(dist));
	dist[1] = 0;

	bool valid = true;
	for (int i = 1; i <= N; ++i) {
		for (piii edge : edges) {
			if (dist[edge.first.first] != INF && dist[edge.first.second] > dist[edge.first.first] + edge.second) {
				dist[edge.first.second] = dist[edge.first.first] + edge.second;
				if (i == N) {
					valid = false;
					break;
				}
			}
		}
	}

	if (!valid) puts("-1");
	else 
		for (int i = 2; i <= N; ++i) printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	return !printf("\n");
}