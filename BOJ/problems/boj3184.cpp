#include <cstdio>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int R, C;
char map[250][251] = {0, };
bool visited[250][250] = {false, };
int global_sheep = 0, global_wolf = 0;
int local_sheep = 0, local_wolf = 0;
int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i=0; i<R; i++) 
		scanf("%s", map[i]);

	queue<point> q;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (map[i][j] != '#' && !visited[i][j]) {
				visited[i][j] = true;
				q.push({i, j});

				local_sheep = local_wolf = 0;
				while(!q.empty()) {
					int r = q.front().r;
					int c = q.front().c;
					q.pop();

					if ( map[r][c] == 'v' ) local_wolf++;
					else if ( map[r][c] == 'o' ) local_sheep++;

					for (int k=0; k<4; k++) {
						int dr = r + move_r[k];
						int dc = c + move_c[k];

						if ( check(dr, dc) && map[dr][dc] != '#' && !visited[dr][dc] ) {
							visited[dr][dc] = true;
							q.push({dr, dc});
						}
					}
				}

				if (local_sheep > local_wolf) global_sheep += local_sheep;
				else global_wolf += local_wolf;
			}
		}
	}

	printf("%d %d\n", global_sheep, global_wolf);

	return 0;
}