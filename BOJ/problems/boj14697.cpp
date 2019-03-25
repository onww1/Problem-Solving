#include <cstdio>
int A, B, C, N;
int main() {
    scanf("%d %d %d %d", &A, &B, &C, &N);
    for (int i = 0; i <= 300; ++i) {
        if (A * i > N) break;
        for (int j = 0; j <= 300; ++j) {
            if (A * i + B * j > N) break;
            for (int k = 0; k <= 300; ++k) {
                if (A * i + B * j + C * k == N) return !printf("1\n");
                else if (A * i + B * j + C * k > N) break;
            }
        }
    }
    puts("0");
    return 0;
}