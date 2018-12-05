#include <cstdio>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int N, M;
char map[1000][1001];
bool visited[1000][1000];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

void init() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%s", map[i]);
	}
}

int main(int argc, char const *argv[])
{
	init();
	bool isOK = false;

	queue<point> q;
	for (int j=0; !isOK && j<M; j++) {
		if (map[0][j] == '0' && !visited[0][j]) {
			q.push({0, j});
			visited[0][j] = true;

			while (!q.empty()) {
				int r = q.front().r;
				int c = q.front().c;
				q.pop();

				if (r == N-1) {
					isOK = true;
					break;
				}

				for (int k=0; k<4; k++) {
					int dr = r + move_r[k];
					int dc = c + move_c[k];

					if (check(dr, dc) && !visited[dr][dc] && map[dr][dc] == '0') {
						q.push({dr, dc});
						visited[dr][dc] = true;
					}
				}
			}
		}
	}

	printf("%s\n", isOK ? "YES" : "NO");
	return 0;
}