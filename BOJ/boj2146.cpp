#include <iostream>
#include <queue>
using namespace std;

struct point {
	int r, c, t;
};

int N, map[100][100];
bool visited[100][100] = {false, };

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++)
			cin >> map[i][j];

	int num = 0;
	queue<point> q, tq;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (!visited[i][j] && map[i][j]) {
				num++;
				map[i][j] = num * 1000;
				visited[i][j] = true;
				q.push({i, j, 0});
				tq.push({i, j, 0});

				while(!q.empty()) {
					int r = q.front().r;
					int c = q.front().c;
					q.pop();

					for (int k=0; k<4; k++) {
						int dr = r + move_r[k];
						int dc = c + move_c[k];

						if (check(dr, dc) && !visited[dr][dc] && map[dr][dc]) {
							visited[dr][dc] = true;
							map[dr][dc] = num * 1000;
							q.push({dr, dc, 0});
							tq.push({dr, dc, 0});
						}
					}
				}
			}
		}
	}

	bool isEnded = false;
	int dist = 10000;
	while (!tq.empty()) {
		int r = tq.front().r;
		int c = tq.front().c;
		int t = tq.front().t;
		tq.pop();

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc)) {
				if (visited[dr][dc] && map[r][c]/1000 != map[dr][dc]/1000) {
					int tmp = (map[r][c] % 1000) + (map[dr][dc] % 1000);
					dist = tmp < dist ? tmp : dist;
					isEnded = true;
					break;
				}
				else if (!visited[dr][dc]) {
					visited[dr][dc] = true;
					map[dr][dc] = map[r][c] + 1;
					if (!isEnded) tq.push({dr, dc, t+1});
				}
			}
		}
	}

	cout << dist << '\n';

	return 0;
}