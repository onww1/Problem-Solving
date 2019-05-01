#include <cstdio>
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", (1 << N) - 1);
    }
    return 0;
}