#include <cstdio>
#include <queue>
using namespace std;

struct point {
	int r, c, f;
};

int N, M;
char map[1000][1001] = { 0, };
int visited[1000][1000][2] = { 0, };

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", map[i]);

	queue<point> q;
	q.push({0, 0, 0});
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int f = q.front().f;
		q.pop();

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc)) {
				if (map[dr][dc] && !f && !visited[dr][dc][1]) {
					visited[dr][dc][1] = visited[r][c][0] + 1;
					q.push({dr, dc, 1});
				}
				if (map[dr][dc] == '0' && !visited[dr][dc][f]) {
					visited[dr][dc][f] = visited[r][c][f] + 1;
					q.push({dr, dc, f});
				}
			}
		}
	}

	int res = 987654321;
	if (visited[N-1][M-1][0]) res = visited[N-1][M-1][0];
	if (visited[N-1][M-1][1]) res = visited[N-1][M-1][1] < res ? visited[N-1][M-1][1] : res;

	printf("%d\n", (res==987654321?-1:res));

	return 0;
}