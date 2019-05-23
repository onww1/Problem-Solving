#include <cstdio>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int N, M, ans = 1, MAP[50][50];
queue <pii> Q;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) {
			scanf("%d", MAP[i] + j);
			if (MAP[i][j]) Q.push({i, j});
		}

	while (!Q.empty()) {
		int r = Q.front().X;
		int c = Q.front().Y;
		Q.pop();

		ans = max(ans, MAP[r][c]);

		for (int k = 0; k < 8; ++k) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];
			if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
			if (!MAP[dr][dc]) {
				MAP[dr][dc] = MAP[r][c] + 1;
				Q.push({dr, dc});
			}
		}
	}

	printf("%d\n", ans - 1);
	return 0;
}