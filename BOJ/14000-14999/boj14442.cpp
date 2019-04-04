#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0b0111'1111'0111'1111'0111'1111'0111'1111
using namespace std;

struct point {
	int r, c, f;
};

int N, M, K;
char map[1000][1001];
int dist[1000][1000][11];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

void init() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i=0; i<N; i++)
		scanf("%s", map[i]);
	memset(dist, 127, sizeof(int) * 1000 * 1000 * 11);
}

int main(int argc, char const *argv[])
{
	init();

	queue<point> q;
	q.push({0, 0, 0});
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int f = q.front().f;
		q.pop();

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc)) {
				if (map[dr][dc] == '1') {
					if (f < K && dist[dr][dc][f+1] > dist[r][c][f] + 1) {
						dist[dr][dc][f+1] = dist[r][c][f] + 1;
						q.push({dr, dc, f+1});
					}
				}
				else if (map[dr][dc] == '0') {
					if (dist[dr][dc][f] > dist[r][c][f] + 1) {
						dist[dr][dc][f] = dist[r][c][f] + 1;
						q.push({dr, dc, f});
					}
				}
			}
		}
	}	

	int min = INF;
	for (int k=0; k<=K; k++) {
		min = min > dist[N-1][M-1][k] ? dist[N-1][M-1][k] : min;
	}

	printf("%d\n", min == INF ? -1 : min);

	return 0;
}