#include <iostream>
#include <queue>
using namespace std;

struct point {
	int r, c, d;
};

int move_r[] = {-3, -2, 2, 3, 3, 2, -2, -3};
int move_c[] = {2, 3, 3, 2, -2, -3, -3, -2};

bool check(int r, int c) {
	if (r < 0 || r > 9 || c < 0 || c > 8) return false;
	return true;
}

bool canGo(int r, int c, int kr, int kc, int k) {
	if (check(r + move_r[k], c + move_c[k])) {
		if (k == 0) {
			if ((kr == r-1 && kc == c) || (kr == r-2 && kc == c+1))
				return false;
			else return true;
		} 
		else if (k == 1) {
			if ((kr == r && kc == c+1) || (kr == r-1 && kc == c+2))
				return false;
			else return true;
		}
		else if (k == 2) {
			if ((kr == r && kc == c+1) || (kr == r+1 && kc == c+2))
				return false;
			else return true;
		}
		else if (k == 3) {
			if ((kr == r+1 && kc == c) || (kr == r+2 && kc == c+1))
				return false;
			else return true;
		}
		else if (k == 4) {
			if ((kr == r+1 && kc == c) || (kr == r+2 && kc == c-1))
				return false;
			else return true;
		}
		else if (k == 5) {
			if ((kr == r && kc == c-1) || (kr == r+1 && kc == c-2))
				return false;
			else return true;
		}
		else if (k == 6) {
			if ((kr == r && kc == c-1) || (kr == r-1 && kc == c-2))
				return false;
			else return true;
		}
		else if (k == 7) {
			if ((kr == r-1 && kc == c) || (kr == r-2 && kc == c-1))
				return false;
			else return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int sr, sc, kr, kc;
	cin >> sr >> sc >> kr >> kc;

	bool visited[10][9] = {false, };
	queue<point> q;

	visited[sr][sc] = true;
	q.push({sr, sc, 0});

	int dist = -1;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		if (kr == r && kc == c) {
			dist = d;
			break;
		}

		for (int k=0; k<8; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (canGo(r, c, kr, kc, k) && !visited[dr][dc]) {
				visited[dr][dc] = true;
				q.push({dr, dc, d+1});
			}
		}
	}

	cout << dist << '\n';

	return 0;
}