#include <cstdio>

int N, M, R, G, B;
char ans[401];

char _parse(int r, int g, int b) {
    int val = 2126 * r + 7152 * g + 722 * b;
    if (val < 510000) return '#';
    if (val < 1020000) return 'o';
    if (val < 1530000) return '+';
    if (val < 2040000) return '-';
    return '.';
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d %d %d", &R, &G, &B);
            ans[j] = _parse(R, G, B);
        }
        printf("%s\n", ans);
    }
    return 0;
}