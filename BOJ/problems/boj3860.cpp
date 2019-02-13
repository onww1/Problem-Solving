#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 900;
const int INF = 0x3f3f3f3f;
const int move_r[] = { 1, 0, -1, 0 };
const int move_c[] = { 0, 1, 0, -1 };

int W, H, G, E, V, dist[MAX + 1];
pii hole[MAX + 1];

bool check(int r, int c) { return r >= 0 && r < H && c >= 0 && c < W; }

int main(int argc, char *argv[]) {
	int x, y, xx, yy, t;
	while (true) {
		scanf("%d %d", &W, &H);
		if (!W && !H) break;
		V = W * H;
		memset(dist, 0x3f, sizeof(dist));
		memset(hole, -1, sizeof(hole));

		scanf("%d", &G);
		for (int i = 0; i < G; ++i) {
			scanf("%d %d", &x, &y);
			dist[y * W + x] = 2 * INF;
		}

		scanf("%d", &E);
		for (int i = 0; i < E; ++i) {
			scanf("%d %d %d %d %d", &x, &y, &xx, &yy, &t);
			hole[y * W + x] = { yy * W + xx, t };
		}

		dist[0] = 0;
		bool valid = true;
		for (int k = 1; k <= V; ++k) {
			for (int i = 0; i < V - 1; ++i) {
				if (dist[i] >= INF) continue;

				int x = i % W, y = i / W;
				if (hole[i].first == -1) {
					for (int j = 0; j < 4; ++j) {
						int dx = x + move_c[j];
						int dy = y + move_r[j];
						if (!check(dy, dx) || dist[dy * W + dx] == 2 * INF) continue;

						if (dist[dy * W + dx] > dist[i] + 1) {
							dist[dy * W + dx] = dist[i] + 1;
							if (k == V) valid = false;
						}
					}
				}
				else if (dist[hole[i].first] > dist[i] + hole[i].second) {
					dist[hole[i].first] = dist[i] + hole[i].second;
					if (k == V) valid = false;
				}
			}
		}

		if (!valid) puts("Never");
		else if (dist[V - 1] == INF) puts("Impossible");
		else printf("%d\n", dist[V - 1]);
	}

	return 0;
}