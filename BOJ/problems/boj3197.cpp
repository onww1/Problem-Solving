#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

struct point {
	int r, c;
};

int R, C;
char map[1500][1501];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

void init() {
	scanf("%d %d", &R, &C);
	for (int i=0; i<R; i++) 
		scanf("%s", map[i]);
}

bool hasAdjacentWater(int r, int c) {
	for (int k=0; k<4; k++) {
		int dr = r + move_r[k];
		int dc = c + move_c[k];

		if (check(dr, dc) && map[dr][dc] == '.')
			return true;
	}
	return false;
}

bool canDucksMeet(vector<point>& ducks, int day) {
	queue<point> q;
	bool visited[1500][1500] = {false, };
	q.push(ducks[0]);
	visited[ducks[0].r][ducks[0].c] = true;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		if (r == ducks[1].r && c == ducks[1].c)
			return true;

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc) && !visited[dr][dc] && map[dr][dc] != 'X') {
				q.push({dr, dc});
				visited[dr][dc] = true;
			}
		}
	}

	return false;
}

void printCurrentState() {
	static int cnt = 0;
	printf("\nday : %d\n", cnt++);
	for (int i=0; i<R; i++) {
		printf("%s\n", map[i]);
	}
}

int main(int argc, char const *argv[])
{
	init();
	// printCurrentState();

	queue<point> q;
	vector<point> target;
	vector<point> ducks;

	int day = 0;
	while (1) {
		day++; 
		bool visited[1500][1500] = {false, };

		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (map[i][j] == 'X' && !visited[i][j]) {
					target.clear();
					q.push({i, j});
					visited[i][j] = true;

					while (!q.empty()) {
						int r = q.front().r;
						int c = q.front().c;
						q.pop();

						if (hasAdjacentWater(r, c)) 
							target.push_back({r, c});

						for (int k=0; k<4; k++) {
							int dr = r + move_r[k];
							int dc = c + move_c[k];

							if (check(dr, dc) && map[dr][dc] == 'X' && !visited[dr][dc]) {
								q.push({dr, dc});
								visited[dr][dc] = true;
							}
						}
					}

					int len = target.size();
					for (int k=0; k<len; k++) {
						map[target[k].r][target[k].c] = '.';
					}
				}
				else if (map[i][j] == 'L') {
					map[i][j] = '.';
					ducks.push_back({i, j});
				}
			}
		}

		// printCurrentState();
		if (canDucksMeet(ducks)) break;
	}

	printf("%d\n", day);

	return 0;
}