#include <cstdio>

const int MAX = 50;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M, T, C, MAP[2][MAX][MAX];

void spread(int tt) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!MAP[tt][i][j] || MAP[tt][i][j] == -1) continue;
            int val = MAP[tt][i][j] / 5;
            for (int k = 0; k < 4; ++k) {
                int dr = i + move_r[k];
                int dc = j + move_c[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= M || MAP[tt][dr][dc] == -1) continue;
                MAP[1 - tt][dr][dc] += val;
                MAP[tt][i][j] -= val;
            }
            MAP[1 - tt][i][j] += MAP[tt][i][j];
            MAP[tt][i][j] = 0;
        }
    }
}

void circulation(int tt) {
    // 위쪽
    for (int i = C - 3; i >= 0; --i) MAP[tt][i + 1][0] = MAP[tt][i][0];
    for (int j = 1; j < M; ++j) MAP[tt][0][j - 1] = MAP[tt][0][j];
    for (int i = 1; i < C; ++i) MAP[tt][i - 1][M - 1] = MAP[tt][i][M - 1];
    for (int j = M - 2; j > 0; --j) MAP[tt][C - 1][j + 1] = MAP[tt][C - 1][j];
    MAP[tt][C - 1][1] = 0;

    // 아래쪽
    for (int i = C + 2; i < N; ++i) MAP[tt][i - 1][0] = MAP[tt][i][0];
    for (int j = 1; j < M; ++j) MAP[tt][N - 1][j - 1] = MAP[tt][N - 1][j];
    for (int i = N - 2; i >= C; --i) MAP[tt][i + 1][M - 1] = MAP[tt][i][M - 1];
    for (int j = M - 2; j > 0; --j) MAP[tt][C][j + 1] = MAP[tt][C][j];
    MAP[tt][C][1] = 0;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &T);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", MAP[0][i] + j);
            if (MAP[0][i][j] == -1) C = i, MAP[1][i][j] = -1;
        }
    }

    for (int t = 0; t < T; ++t) {
        spread(t % 2);
        circulation(1 - t % 2);
    }

    int ans = 2;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < M; ++j) 
            ans += MAP[T % 2][i][j];
    printf("%d\n", ans);
    return 0;
}