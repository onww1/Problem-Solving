#include <cstdio>

int N, M;
char src[50][51], dst[50][51];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) scanf(" %s", src[i]);
    for (int i = 0; i < N; ++i) scanf(" %s", dst[i]);

    int ans = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = 0; j < M - 2; ++j) {
            if (src[i][j] != dst[i][j]) {
                ans++;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (src[i + k][j + l] == '0') src[i + k][j + l] = '1';
                        else src[i + k][j + l] = '0';
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (src[i][j] != dst[i][j]) return !printf("-1\n");
        }
    }

    printf("%d\n", ans);
    return 0;
}