#include <cstdio>

int N, M, A[101], C[101];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) scanf("%d", A + i);
    for (int i = 0; i < M; ++i) {
        int cnt = 0;
        for (int j = 0, B; j < N; ++j) {
            scanf("%d", &B);
            if (B == A[i]) C[j]++;
            else cnt++;
        }
        C[A[i] - 1] += cnt;
    }
    for (int i = 0; i < N; ++i) printf("%d\n", C[i]);
    return 0;
}