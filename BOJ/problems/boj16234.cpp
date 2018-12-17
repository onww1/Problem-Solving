#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

int N, L, R;
int map[50][50] = {0, };

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

int abs(int a) { return a > 0 ? a : -a; }

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> L >> R;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = -1;
	bool keepGoing = true;
	while (keepGoing) {
		cnt++;
		keepGoing = false;
		bool visited[50][50] = {false, };
		vector<point> uni;

		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					uni.clear();
					queue<point> q;
					uni.push_back({i, j});
					q.push({i, j});

					while (!q.empty()) {
						int r = q.front().r;
						int c = q.front().c;
						q.pop();

						for (int k=0; k<4; k++) {
							int dr = r + move_r[k];
							int dc = c + move_c[k];
							if (check(dr, dc) && !visited[dr][dc]) {
								int diff = abs(map[r][c] - map[dr][dc]);
								if (L <= diff && diff <= R) {
									q.push({dr, dc});
									uni.push_back({dr, dc});
									visited[dr][dc] = true;
								}
							}
						}
					}

					int len = uni.size();
					if (len == 1) {
						continue;
					}
					else {
						keepGoing = true;
						int sum = 0;
						for (int region = 0; region < len; region++) {
							sum += map[uni[region].r][uni[region].c];
						}
						sum /= len;
						for (int region = 0; region < len; region++) {
							map[uni[region].r][uni[region].c] = sum;
						}
					}
				}
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}