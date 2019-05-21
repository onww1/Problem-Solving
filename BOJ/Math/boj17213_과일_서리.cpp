#include <cstdio>
#include <cstring>

int N, M, DP[30][30];

int solve(int n, int k) {
    if (n == k || k == 0) return 1;
    if (DP[n][k] != -1) return DP[n][k];
    return DP[n][k] = solve(n - 1, k - 1) + solve(n - 1, k);
}

int main(int argc, char *argv[]) {
    memset(DP, -1, sizeof(DP));
    scanf("%d %d", &N, &M);
    printf("%d\n", solve(M - 1, M - N));
    return 0;
}