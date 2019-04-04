#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int T, N, M;
char map[100][101];
bool visited[100][100];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

void init() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", map[i]);
	memset(visited, false, 100 * N);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &T);
	while (T--) {
		init();
		queue<point> q;
		int cnt = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (map[i][j] == '#' && !visited[i][j]) {
					q.push({i, j});
					visited[i][j] = true;
					++cnt;

					while (!q.empty()) {
						int r = q.front().r;
						int c = q.front().c;
						q.pop();
						
						for (int k=0; k<4; k++) {
							int dr = r + move_r[k];
							int dc = c + move_c[k];

							if (check(dr, dc) && !visited[dr][dc] && map[dr][dc] == '#') {
								q.push({dr, dc});
								visited[dr][dc] = true;
							}
						}
					}
				}
			}
		}

		printf("%d\n" ,cnt);
	}
	return 0;
}