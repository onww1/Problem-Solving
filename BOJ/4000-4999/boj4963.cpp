#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int W, H, cnt;
bool map[50][50];
bool visited[50][50];

int move_r[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int move_c[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check(int r, int c) {
	if (r < 0 || r >= H || c < 0 || c >= W) return false;
	return true;
}

void init() {
	cin >> W >> H;
	memset(visited, false, 50 * H);

	int in;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> in;
			map[i][j] = in == 1;
		}
	}

	cnt = 0;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	while (true) {
		init();
		if (!W && !H) break;

		queue<point> q;
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if (!visited[i][j] && map[i][j]) {
					cnt++;

					q.push({i, j});
					visited[i][j] = true;

					while (!q.empty()) {
						int r = q.front().r;
						int c = q.front().c;
						q.pop();

						for (int k=0; k<8; k++) {
							int dr = r + move_r[k];
							int dc = c + move_c[k];

							if (check(dr, dc) && !visited[dr][dc] && map[dr][dc]) {
								q.push({dr, dc});
								visited[dr][dc] = true;
							}
						}
					}
				}
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}