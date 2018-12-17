#include <iostream>
#include <vector>
using namespace std;

struct CCTV {
	int r, c;
	int type;
};

int move_r[] = {0, 0, 1, -1};
int move_c[] = {1, -1, 0, 0};

enum _DIRECTION { 
	EAST, WEST, SOUTH, NORTH
} DIRECTION;

int check(int r, int c, int R, int C) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

void fill(vector< vector<int> >& map, CCTV cctv, int direction, int val) {
	int dr = cctv.r + move_r[direction];
	int dc = cctv.c + move_c[direction];
	int R = map.size();
	int C = map[0].size();

	while (check(dr, dc, R, C) && map[dr][dc] != 6) {
		if (map[dr][dc] == 0)
			map[dr][dc] = val;
		dr += move_r[direction];
		dc += move_c[direction];
	}
}

void erase(vector< vector<int> >& map, CCTV cctv, int direction, int val) {
	int dr = cctv.r + move_r[direction];
	int dc = cctv.c + move_c[direction];
	int R = map.size();
	int C = map[0].size();

	while (check(dr, dc, R, C) && map[dr][dc] != 6) {
		if (map[dr][dc] == val)
			map[dr][dc] = 0;
		dr += move_r[direction];
		dc += move_c[direction];
	}
}

void solve(vector< vector<int> >& map, vector<CCTV>& cctvs, int T, int& min) {

	if (T == cctvs.size()) {
		int N = map.size();
		int M = map[0].size();

		int cnt = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (!map[i][j]) cnt++;
			}
		}
		min = cnt < min ? cnt : min;
		return;
	}

	CCTV cctv = cctvs[T];
	if (cctv.type == 1) {
		fill(map, cctv, EAST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, EAST, -(T+1));

		fill(map, cctv, WEST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, WEST, -(T+1));

		fill(map, cctv, SOUTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, SOUTH, -(T+1));

		fill(map, cctv, NORTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, NORTH, -(T+1));
	}
	else if (cctv.type == 2) {
		fill(map, cctv, EAST, -(T+1));
		fill(map, cctv, WEST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, EAST, -(T+1));
		erase(map, cctv, WEST, -(T+1));

		fill(map, cctv, SOUTH, -(T+1));
		fill(map, cctv, NORTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, SOUTH, -(T+1));
		erase(map, cctv, NORTH, -(T+1));
	}
	else if (cctv.type == 3) {
		fill(map, cctv, NORTH, -(T+1));
		fill(map, cctv, EAST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, NORTH, -(T+1));

		fill(map, cctv, SOUTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, EAST, -(T+1));

		fill(map, cctv, WEST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, SOUTH, -(T+1));

		fill(map, cctv, NORTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, WEST, -(T+1));
		erase(map, cctv, NORTH, -(T+1));
	}
	else if (cctv.type == 4) {
		fill(map, cctv, WEST, -(T+1));
		fill(map, cctv, NORTH, -(T+1));
		fill(map, cctv, EAST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, WEST, -(T+1));

		fill(map, cctv, SOUTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, NORTH, -(T+1));

		fill(map, cctv, WEST, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, EAST, -(T+1));

		fill (map, cctv, NORTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, NORTH, -(T+1));
		erase(map, cctv, SOUTH, -(T+1));
		erase(map, cctv, WEST, -(T+1));
	}
	else if (cctv.type == 5) {
		fill(map, cctv, WEST, -(T+1));
		fill(map, cctv, NORTH, -(T+1));
		fill(map, cctv, EAST, -(T+1));
		fill(map, cctv, SOUTH, -(T+1));
		solve(map, cctvs, T+1, min);
		erase(map, cctv, NORTH, -(T+1));
		erase(map, cctv, SOUTH, -(T+1));
		erase(map, cctv, WEST, -(T+1));
		erase(map, cctv, EAST, -(T+1));
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	vector< vector<int> > map;
	vector<CCTV> cctvs;

	cin >> N >> M;
	map.resize(N);
	for (int i=0; i<N; i++) {
		map[i].resize(M);
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
			if (map[i][j] && map[i][j] != 6)
				cctvs.push_back({i, j, map[i][j]});
		}
	}

	int min = 987654321;
	solve(map, cctvs, 0, min);

	cout << min << '\n';
	return 0;
}