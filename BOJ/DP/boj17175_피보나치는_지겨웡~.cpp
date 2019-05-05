#include <cstdio>
const int MOD = 1e9 + 7;
int fibo[55], N;
int main(int argc, char *argv[]) {
    scanf("%d", &N);
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i <= 50; ++i) fibo[i] = (fibo[i - 1] + fibo[i - 2] + 1) % MOD;
    printf("%d\n", fibo[N]);
    return 0;
}