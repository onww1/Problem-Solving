#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int map[101][101] = { 0, };
	int area[101] = { 0, };
	int N, r, c, h, w;

	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> r >> c >> h >> w;
		area[i] = w * h;
		for (int R = r; R < r + h; R++) {
			for (int C = c; C < c + w; C++) {
				if (map[R][C]) {
					area[map[R][C]]--;
				}
				map[R][C] = i;
			}
		}
	}

	for (int i=1; i<=N; i++) {
		cout << area[i] << '\n';
	}

	return 0;
}