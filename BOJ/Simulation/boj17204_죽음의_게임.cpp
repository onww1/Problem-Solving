#include <cstdio>

int N, K, ans, A[150], V[150];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);

    int pos = 0;
    while (1) {
        if (V[pos]) return !printf("-1\n");
        V[pos] = true;
        if (pos == K) break;
        pos = A[pos];
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}