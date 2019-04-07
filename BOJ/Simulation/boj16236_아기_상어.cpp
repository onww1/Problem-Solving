#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct fish {
	int r, c, dist;
};

bool cmp(fish& a, fish& b) {
	if (a.dist == b.dist && a.r == b.r) return a.c < b.c;
	else if (a.dist == b.dist) return a.r < b.r;
	else return a.dist < b.dist;
}

int N, map[20][20], t = 0, size = 2, food = 0;
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

	queue<fish> q;

	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				q.push({i, j, 0});
				map[i][j] = 0;
			}
		}
	}

	bool keepGoing = true;
	while (keepGoing) {
		bool visited[20][20] = {false, };
		visited[q.front().r][q.front().c] = true;
		vector<fish> closed;

		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int d = q.front().dist;
			q.pop();

			if (!closed.empty()) {
				if (closed[0].dist == d)
					break;
			}

			for (int k=0; k<4; k++) {
				int dr = r + move_r[k];
				int dc = c + move_c[k];

				if (check(dr, dc) && !visited[dr][dc]) {
					if (map[dr][dc] <= size) {
						visited[dr][dc] = true;
						q.push({dr, dc, d+1});
						
					}
					if (map[dr][dc] && map[dr][dc] < size) 
						closed.push_back({dr, dc, d+1});
				}
			}
		}

		if (closed.empty()) {
			keepGoing = false;
		}
		else {
			sort(closed.begin(), closed.end(), cmp);
			t += closed[0].dist;
			map[closed[0].r][closed[0].c] = 0;
			food++;
			if (size == food) {
				size++;
				food = 0;
			}
			while (!q.empty()) q.pop();
			q.push({closed[0].r, closed[0].c, 0});
			closed.clear();
		}
	}

	cout << t << '\n';

	return 0;
}