#include <cstdio>

int T, N, A[80001];

int main(int argc, char *argv[]) {
    for (int i = 3; i <= 80000; ++i) {
        A[i] += A[i - 1];
        if (i % 3 == 0 || i % 7 == 0)
            A[i] += i;
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", A[N]);
    }
    
    return 0;
}