#include <algorithm>
#include <cstdio>
#include <set>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, K, R, C, MAP[100][100];
set <int> road[10000];
pii cow[100];

void dfs(int r, int c, int color) {
    MAP[r][c] = color;
    int cur = r * N + c;
    for (int k = 0; k < 4; ++k) {
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
        if (!MAP[dr][dc]) {
            int p = dr * N + dc;
            if (road[cur].count(p)) continue;
            dfs(dr, dc, color);    
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &K, &R);
    for (int i = 0, r, c, rr, cc; i < R; ++i) {
        scanf("%d %d %d %d", &r, &c, &rr, &cc);
        int p1 = (r - 1) * N + c - 1;
        int p2 = (rr - 1) * N + cc - 1;
        road[p1].insert(p2);
        road[p2].insert(p1);
    }

    for (int i = 0; i < K; ++i) {
        scanf("%d %d", &cow[i].X, &cow[i].Y);
        cow[i].X--, cow[i].Y--;
    }

    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            if (!MAP[i][j]) dfs(i, j, ++C);

    int ans = 0;
    for (int i = 0; i < K - 1; ++i) 
        for (int j = i + 1; j < K; ++j)
            if (MAP[cow[i].X][cow[i].Y] != MAP[cow[j].X][cow[j].Y])
                ans++;

    printf("%d\n", ans);
    return 0;
}
