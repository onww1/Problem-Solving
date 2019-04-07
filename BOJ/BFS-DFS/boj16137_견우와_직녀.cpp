#include <iostream>
#include <cstring>
#include <queue>
#define INF 0b0111'1111'0111'1111'0111'1111'0111'1111
using namespace std;

struct point {
	int r, c, flag;
};

int N, M, map[10][10];
int dist[10][10][2];

int move_r[] = {-1, 0, 1, 0};
int move_c[] = {0, -1, 0, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

bool isCross(int r, int c) {
	bool cross = false;
	for (int k=0; k<4; k++) {
		int dr1 = r + move_r[k], dr2 = r + move_r[(k+1)%4];
		int dc1 = c + move_c[k], dc2 = c + move_c[(k+1)%4];
		cross = cross || (map[dr1][dc1] != 1 && map[dr2][dc2] != 1);
	}
	return cross;
}

void printCurrentState(int r, int c) {
	cout << '\n' << "current position // (r, c) : (" << r << ", " << c << ")\n";
	cout << "0 flag case\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << (dist[i][j][0] == INF?10000:dist[i][j][0]) << '\t';
		}
		cout << '\n';
	}
	cout << "1 flag case\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << (dist[i][j][1] == INF?10000:dist[i][j][1]) << '\t';
		}
		cout << '\n';
	}
}

void init() {
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	
	memset(dist, 127, sizeof(int) * 10 * 10 * 2);
}

int main(int argc, char const *argv[])
{
	init();

	queue<point> q;
	dist[0][0][0] = 0;
	q.push({0, 0, 0});

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int f = q.front().flag;
		q.pop();

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc)) {
				if (map[dr][dc] == 0) {
					if (!f && !isCross(dr, dc) && map[r][c] == 1) {
						int t = dist[r][c][f] / M * M + M;
						dist[dr][dc][1] = t;
						q.push({dr, dc, 1});
					}
				}
				else if (map[dr][dc] == 1) {
					if (dist[dr][dc][f] > dist[r][c][f] + 1) {
						dist[dr][dc][f] = dist[r][c][f] + 1;
						q.push({dr, dc, f});
					}
				}
				else if (map[dr][dc] > 1) {
					if (map[r][c] == 1) {
						int t = dist[r][c][f] / map[dr][dc] * map[dr][dc] + map[dr][dc];
						if (dist[dr][dc][f] > t) {
							dist[dr][dc][f] = t;
							q.push({dr, dc, f});
						}
					}
				}
			}
		}

		// printCurrentState(r, c);
	}

	int min = INF;
	if (dist[N-1][N-1][0] != INF) min = dist[N-1][N-1][0];
	if (dist[N-1][N-1][1] != INF) min = dist[N-1][N-1][1] < min ? dist[N-1][N-1][1] : min;
	cout << min << '\n';

	return 0;
}