#include <iostream>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int R, C;
char map[100][101] = { 0, };
bool visited[100][100] = { false, };

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

int main() {
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		scanf("%s", map[i]);
	}

	queue<point> q;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (map[i][j] == 'W') {
				visited[i][j] = true;
				q.push({i, j});
			}
		}
	}

	while(!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (!visited[dr][dc]) {
				if (map[dr][dc] == '.') {
					visited[dr][dc] = true;
					q.push({dr, dc});
				}
				else if(map[dr][dc] == '+') {
					int ddr = dr;
					int ddc = dc;

					while (map[ddr][ddc] == '+') {
						visited[ddr][ddc] = true;
						ddr += move_r[k];
						ddc += move_c[k];
					}

					if(map[ddr][ddc] == '#') {
						ddr -= move_r[k];
						ddc -= move_c[k];
					}
					else {
						visited[ddr][ddc] = true;
					}
				
					q.push({ddr, ddc});
				}
			}
		}
	}

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (map[i][j] == '.' && !visited[i][j])
				map[i][j] = 'P';
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}