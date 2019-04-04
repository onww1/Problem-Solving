#include <cstdio>
#include <cstring>
using namespace std;

int T, N, M, MAX, CNT;
char map[10][11];
bool visited[10][10];

int move_r[] = {-1, -1, 0, 0};
int move_c[] = {-1, 1, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

void fill(int r, int c, bool flag) {
	visited[r][c] = flag;
	for (int k=0; k<4; k++) {
		int dr = r + move_r[k];
		int dc = c + move_c[k];

		if (check(dr, dc)) visited[dr][dc] = flag;
	}
}

void dfs(int r, int c) {
	bool isEnded = true;

	for (int j=c+1; j<M; j++) {
		if (map[r][j] == '.' && !visited[r][j]) {
			isEnded = false;
			CNT++;
			fill(r, j, true);
			dfs(r, j);
			fill(r, j, false);
			CNT--;
		}
	}

	for (int i=r+1; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (map[i][j] == '.' && !visited[i][j]) {
				isEnded = false;
				CNT++;
				fill(i, j, true);
				dfs(i, j);
				fill(i, j, false);
				CNT--;
			}
		}
	}

	if (isEnded) {
		MAX = CNT > MAX ? CNT : MAX;
		return;
	}
}

void init() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; ++i) 
		scanf("%s", map[i]);

	memset(visited, false, 10 * N);
	MAX = -1;
	CNT = 0;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &T);

	while (T--) {
		init();
		dfs(0, -1);
		printf("%d\n", MAX);
	}

	return 0;
}