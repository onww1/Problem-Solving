#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int UNVISITED = -1;
const int MAX = 500;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};

int N, M, D, C[MAX][MAX];
char MAP[MAX][MAX + 1];
queue <pii> Q;

void dfs(int r, int c, int v) {
    if (C[r][c] != UNVISITED) return;
    C[r][c] = v;
    Q.push({r, c});
    for (int k = 0; k < 4; ++k) {
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
        if (C[dr][dc] == UNVISITED && MAP[dr][dc] == '.') dfs(dr, dc, v);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &D);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);
    memset(C, -1, sizeof(C));
    dfs(0, 0, 0);

    while (!Q.empty()) {
        int r = Q.front().X, c = Q.front().Y; Q.pop();
        if (C[N - 1][M - 1] != UNVISITED) break;

        for (int i = r - D + 1, cc; i <= r + D - 1; ++i) {
            if (i < 0 || i >= N) continue;
            cc = min(c + D, M - 1);
            dfs(i, cc, C[r][c] + 1);
            cc = max(c - D, 0);
            dfs(i, cc, C[r][c] + 1);
        }

        for (int j = c - D + 1, rr; j <= c + D - 1; ++j) {
            if (j < 0 || j >= M) continue;
            rr = min(r + D, N - 1);
            dfs(rr, j, C[r][c] + 1);
            rr = max(r - D, 0);
            dfs(rr, j, C[r][c] + 1);
        }
    }
  
    printf("%d\n", C[N - 1][M - 1]);
    return 0;
}