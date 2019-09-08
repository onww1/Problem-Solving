#include <cstdio>
const int MOD = 1e9 + 7;
int n, m, dp[205][205];
char in[205][205];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf(" %s", in[i] + 1);
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (in[i][j] != 'X')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    printf("%d\n", dp[n][m]);
    return 0;
}