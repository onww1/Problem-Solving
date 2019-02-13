#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 100;
const int INF = 0x3f3f3f3f;
int N, M, dist[MAX + 1][MAX + 1];

int main(int argc, char *argv[]) {
	int u, v, w;
	scanf("%d %d", &N, &M);

	memset(dist, 0x3f, sizeof(dist));
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		dist[u][v] = min(dist[u][v], w);
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (i == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) 
			printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);
		puts("");
	}
	return 0;
}