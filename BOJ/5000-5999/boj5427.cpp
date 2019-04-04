#include <cstdio>
#include <cstring>
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
	scanf("%d %d", &C, &R);
	for (int i=0; i<R; ++i) scanf("%s", map[i]);
	memset(visited, false, R * 1000);
	res = -1;
}

void process() {
	queue<point> q;

	// store the J's position
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (map[i][j] == '@') {
				q.push({i, j, 0, '@'});
				visited[i][j] = true;
				break;
			}
		}
	}

	// store the F's positions
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (map[i][j] == '*') {
				q.push({i, j, 0, '*'});
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

		if (what == '@' && map[r][c] == '*') continue;
		if (what == '@' && isBoundary(r, c)) {
			res = t + 1;
			break;
		}

		for (int k=0; k<4; ++k) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc)) {
				if (map[dr][dc] == '.' || map[dr][dc] == '@') {
					if (!visited[dr][dc] || (what == '*' && map[dr][dc] == '@')) {
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
	int T;
	scanf("%d", &T);
	while (T--) {
		input();
		process();
		output();
	}
	return 0;
}