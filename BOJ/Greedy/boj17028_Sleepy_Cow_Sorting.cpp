#include <cstdio>

int N, cnt, A[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);

    cnt = 1;
    for (int i = N - 2; i >= 0; --i) {
        if (A[i] < A[i + 1]) cnt++;
        else break;
    }

    printf("%d\n", N - cnt);
    return 0;
}