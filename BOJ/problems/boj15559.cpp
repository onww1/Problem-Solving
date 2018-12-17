#include <cstdio>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int N, M;
char map[1000][1001];
int visited[1000][1000];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

int parse(char c) {
	if (c == 'N') return 0;
	else if (c == 'S') return 1;
	else if (c == 'W') return 2;
	else if (c == 'E') return 3;
	return -1;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%s", map[i]);
	}

	queue<point> q;
	int num = 0;
	int cnt = 0;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (!visited[i][j]) {
				num++;
				cnt++;
				q.push({i, j});
				visited[i][j] = num;

				while (!q.empty()) {
					int r = q.front().r;
					int c = q.front().c;
					q.pop();

					int d = parse(map[r][c]);
					int dr = r + move_r[d];
					int dc = c + move_c[d];

					if (!visited[dr][dc]) {
						visited[dr][dc] = num;
						q.push({dr, dc});
					}
					else if (visited[dr][dc] != num) {
						cnt--;
					}
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}