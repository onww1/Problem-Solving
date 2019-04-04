#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 1e2;
const int INF = 0x7f7f7f7f;
const int move_r[] = {0, 1, 0, -1};
const int move_c[] = {1, 0, -1, 0};
int N, M, MAP[MAX][MAX], T[4][MAX][MAX];
piii SRC, DST;

int parse(int d) { 
    if (d == 1) return 0;
    else if (d == 2) return 2;
    else if (d == 3) return 1;
    return 3;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf("%d", &MAP[i][j]);
    scanf("%d %d %d", &SRC.Y.X, &SRC.Y.Y, &SRC.X); 
    scanf("%d %d %d", &DST.Y.X, &DST.Y.Y, &DST.X); 
    SRC.X = parse(SRC.X); SRC.Y.X--; SRC.Y.Y--;
    DST.X = parse(DST.X); DST.Y.X--; DST.Y.Y--;
    memset(T, 0x7f, sizeof(T));

    queue <piii> Q;
    Q.push(SRC);
    T[SRC.X][SRC.Y.X][SRC.Y.Y] = 0;

    while (!Q.empty()) {
        int d = Q.front().X;
        int r = Q.front().Y.X;
        int c = Q.front().Y.Y;
        Q.pop();

        if (d == DST.X && r == DST.Y.X && c == DST.Y.Y) break;

        // 직진
        for (int x = 1; x <= 3; ++x) {
            int dr = r + move_r[d] * x;
            int dc = c + move_c[d] * x;
            if (dr < 0 || dr >= N || dc < 0 || dc >= M || MAP[dr][dc] || T[d][dr][dc] < T[d][r][c] + 1) break;
            T[d][dr][dc] = T[d][r][c] + 1;
            Q.push({d, {dr, dc}});
        }

        // 왼쪽 회전
        if (T[(d + 3) % 4][r][c] > T[d][r][c] + 1) {
            T[(d + 3) % 4][r][c] = T[d][r][c] + 1;
            Q.push({(d + 3) % 4, {r, c}});
        }

        // 오른쪽 회전
        if (T[(d + 1) % 4][r][c] > T[d][r][c] + 1) {
            T[(d + 1) % 4][r][c] = T[d][r][c] + 1;
            Q.push({(d + 1) % 4, {r, c}});
        }
    }

    printf("%d\n", T[DST.X][DST.Y.X][DST.Y.Y] == INF ? -1 : T[DST.X][DST.Y.X][DST.Y.Y]);
    return 0;
}