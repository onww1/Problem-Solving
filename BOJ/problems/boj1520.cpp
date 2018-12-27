#include <iostream>
#include <cstring>
using namespace std;

int N, M, H[501][501], DP[501][501];
int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

int solve(int r, int c) {
	if (r == 0 && c == 0) return 1;
	int &ret = DP[r][c];
	if (ret != -1) return ret;

	ret = 0;
	for (int k=0; k<4; ++k) {
		int dr = r + move_r[k];
		int dc = c + move_c[k];
		if (check(dr, dc) && H[r][c] < H[dr][dc]) {
			ret += solve(dr, dc);
		}
	}
	return ret;
}

int main(int argc, char *argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin >> H[i][j];

	memset(DP, -1, sizeof(int) * 500 * 500);
	cout << solve(N-1, M-1) << '\n';

	return 0;
}
