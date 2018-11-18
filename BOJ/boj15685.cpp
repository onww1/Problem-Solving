#include <iostream>
#include <vector>

using namespace std;

int move_r[] = {0, -1, 0, 1};
int move_c[] = {1, 0, -1, 0};

struct point {
	int r, c;
};

void draw(bool map[101][101], vector<point>& points, int t, int g) {
	if (t == g) return;

	point pivot = points.back();
	int Or = pivot.r;
	int Oc = pivot.c;

	int len = points.size();
	for (int i = len-2; i>=0; i--) {
		int dr = points[i].r - Or;
		int dc = points[i].c - Oc;

		map[Or + dc][Oc - dr] = true;
		points.push_back({Or + dc, Oc - dr});
	}
	draw(map, points, t+1, g);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool map[101][101] = { false, };
	vector<point> points;

	int N, x, y, d, g;
	cin >> N;

	while (N--) {
		cin >> x >> y >> d >> g;
		points.clear();

		map[y][x] = true;
		map[y + move_r[d]][x + move_c[d]] = true;
		points.push_back({y, x});
		points.push_back({y + move_r[d], x + move_c[d]});
		draw(map, points, 0, g);
	}

	int cnt = 0;
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
				cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}