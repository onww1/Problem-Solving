#include <cstdio>
#include <queue>
using namespace std;

struct point {
	int r, c, t;
	char what;
};

int R, C, res = -1;
char map[1000][1001];
bool visited[1000][1000] = {false, };

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

bool isBoundary(int r, int c) {
	if (r == 0 || c == 0 || r == R-1 || c == C-1) return true;
	return false;
}

void input() {
	scanf("%d %d", &R, &C);
	for (int i=0; i<R; ++i) scanf("%s", map[i]);
}

void process() {
	queue<point> q;

	// store the J's position
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (map[i][j] == 'J') {
				q.push({i, j, 0, 'J'});
				visited[i][j] = true;
				break;
			}
		}
	}

	// store the F's positions
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (map[i][j] == 'F') {
				q.push({i, j, 0, 'F'});
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int t = q.front().t;
		char what = q.front().what;
		q.pop();

		if (what == 'J' && map[r][c] == 'F') continue;
		if (what == 'J' && isBoundary(r, c)) {
			res = t + 1;
			break;
		}

		for (int k=0; k<4; ++k) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc)) {
				if (map[dr][dc] == '.' || map[dr][dc] == 'J') {
					if (!visited[dr][dc] || (what == 'F' && map[dr][dc] == 'J')) {
						visited[dr][dc] = true;
						map[dr][dc] = what;
						q.push({dr, dc, t+1, what});
					}
				}
			}
		}
	}
}

void output() {
	if (res == -1) printf("IMPOSSIBLE\n");
	else printf("%d\n", res);
}

int main(int argc, char const *argv[])
{
	input();
	process();
	output();
	return 0;
}