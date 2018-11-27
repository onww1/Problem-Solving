#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int r, c;
};

int R, C, N, map[300][300];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

int countZeros(int r, int c) {
	int cnt = 0;
	for (int k=0; k<4; k++) {
		int dr = r + move_r[k];
		int dc = c + move_c[k];

		if (check(dr, dc) && !map[dr][dc]) cnt++;
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> map[i][j];
			if (map[i][j]) N++;
		}
	}

	bool keepGoing = true;
	queue<point> q;
	vector<point> v;
	int Time = 0;

	while (keepGoing) {
		Time++;
		if (N == 0) break;

		bool visited[300][300] = { false, };
		bool loop = true;
		for (int i=0; loop && i<R; i++) {
			for (int j=0; loop && j<C; j++) {
				if (!visited[i][j] && map[i][j]) {
					visited[i][j] = true;
					q.push({i, j});

					int remain = N;
					while (!q.empty()) {
						int r = q.front().r;
						int c = q.front().c;
						q.pop();
						remain--;

						int zeros = countZeros(r, c);
						if (map[r][c] - zeros <= 0) v.push_back({r, c});
						else map[r][c] -= zeros;

						for (int k=0; k<4; k++) {
							int dr = r + move_r[k];
							int dc = c + move_c[k];

							if (check(dr, dc) && !visited[dr][dc] && map[dr][dc]) {
								visited[dr][dc] = true;
								q.push({dr, dc});
							}
						}
					}

					if (remain > 0) {
						loop = false;
						keepGoing = false;
					}
					else {
						int len = v.size();
						N -= len;
						for (int k=0; k<len; k++)
							map[v[k].r][v[k].c] = 0;
						v.clear();
					}
				}
			}
		}
	}

	if (N == 0) cout << 0 << '\n';
	else cout << (Time - 1) << '\n';

	return 0;
}