#include <iostream>
using namespace std;

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c, int N, int M) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, H[500][500], DP[500][500] = {0, };
	cin >> N >> M;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			cin >> H[i][j];
		}
	}

	
	return 0;
}