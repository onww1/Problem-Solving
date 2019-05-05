#include <cstdio>

int N, M, K, S;
bool mul[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &K);
        for (int j = 1; K * j <= N; ++j) {
            if (!mul[K * j]) {
                mul[K * j] = true;
                S += K * j;
            }
        }
    }

    printf("%d\n", S);
    return 0;
}