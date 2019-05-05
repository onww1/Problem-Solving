#include <cstdio>
int N, M, S;
int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    while (N) {
        S += N;
        N /= M;
    }
    printf("%d\n", S);
    return 0;
}