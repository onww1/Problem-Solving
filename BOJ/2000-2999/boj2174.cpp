#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct robot {
	int r, c, d;
};

int move_r[] = {0, 1, 0, -1};
int move_c[] = {1, 0, -1, 0};

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int C, R, n, m;
	int map[100][100] = {0, };
	vector<robot> robots;

	cin >> C >> R >> n >> m;

	int c, r; char d;
	for (int i=0; i<n; i++) {
		cin >> c >> r >> d;
		int direction = 0;
		if (d == 'E') direction = 0;
		else if (d == 'N') direction = 1;
		else if (d == 'W') direction = 2;
		else if (d == 'S') direction = 3;
		robots.push_back({r-1, c-1, direction});
		map[r-1][c-1] = i+1;
	}

	int idx, rep; char cmd;
	string str = "OK";
	bool isEnded = false;
	for (int i=0; i<m; i++) {
		cin >> idx >> cmd >> rep;
		if (!isEnded && cmd == 'L') {
			robots[idx-1].d = (robots[idx-1].d + rep)%4;
		}
		else if (!isEnded && cmd == 'R') {
			robots[idx-1].d = (robots[idx-1].d + 3 * rep)%4;
		}
		else if (!isEnded && cmd == 'F') {
			int orgR = robots[idx-1].r;
			int orgC = robots[idx-1].c;
			int direction = robots[idx-1].d;
			int curR = orgR;
			int curC = orgC;
			for (int j=0; !isEnded && j<rep; j++) {
				curR += move_r[direction];
				curC += move_c[direction];
				if (curR < 0 || curR >= R || curC < 0 || curC >= C) {
					str = string("Robot ") + to_string(idx) + string(" crashes into the wall");
					isEnded = true;
				}
				else if (map[curR][curC] && map[curR][curC] != idx) {
					str = string("Robot ") + to_string(idx) + string(" crashes into robot ") + to_string(map[curR][curC]);
					isEnded = true;
				}
			}
			if (!isEnded) {
				map[orgR][orgC] = 0;
				robots[idx-1].r = curR;
				robots[idx-1].c = curC;
				map[curR][curC] = idx;
			}
		}
	}

	cout << str << '\n';
	return 0;
}