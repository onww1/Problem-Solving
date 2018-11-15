#include <iostream>
#include <queue>
using namespace std;

struct point {
	int r, c;
};

int R, C, N;
int map[300][300] = { 0, };
int snapshot[300][300];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

int numOfAdjacentZeros(int r, int c) {
	int cnt = 0;
	for (int k=0; k<4; k++) {
		int dr = r + move_r[k];
		int dc = c + move_c[k];

		if (check(dr, dc) && !snapshot[dr][dc]) 
			cnt++;
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> map[i][j];
			if (map[i][j]) N++;
		}
	}

	bool keepRunning = true;
	int T = 0;
	queue<point> q;
	for (int i=0; keepRunning && i<R; i++) {
		for (int j=0; keepRunning && j<C; j++) {
			if ( N == 0 ) {
				keepRunning = false;
				cout << 0 << '\n';
			}
			else if ( map[i][j] ) {
				T++;
				bool visited[300][300] = { false, };		
				for (int i=0; i<R; i++) 
					for (int j=0; j<C; j++) 
						snapshot[i][j] = map[i][j];

				q.push({i, j});
				visited[i][j] = true;
				
				int tot = N;
				while (!q.empty()) {
					int r = q.front().r;
					int c = q.front().c;
					q.pop();
					tot--;

					int dec = numOfAdjacentZeros(r, c);
					if ( map[r][c] - dec <= 0 ) N--;
					map[r][c] = ( map[r][c] - dec <= 0 ? 0 : map[r][c] - dec );

					for (int k=0; k<4; k++) {
						int dr = r + move_r[k];
						int dc = c + move_c[k];

						if (check(dr, dc) && !visited[dr][dc] && snapshot[dr][dc]) {
							visited[dr][dc] = true;
							q.push({dr, dc});
						}
					}
				}

				if (tot > 0) {
					keepRunning = false;
					cout << (T - 1) << '\n';
				}

			}
		}
	}

	return 0;
}