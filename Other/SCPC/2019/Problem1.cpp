#include <algorithm>
#include <cstdio>

const int MAX = 1e6 + 1;
int t, n1, n2, dp[MAX], psum[MAX];

int solve(int n) {
    if (n == 1) return 0;

    int &ret = dp[n];
    if (ret) return ret;
    if (n % 2) ret = 1 + solve(n + 1);
    else ret = 1 + solve(n / 2);

    return ret;
}

int main(int argc, char *argv[]) {
    for (int i = 2; i < MAX; ++i) {
        solve(i);
        psum[i] = dp[i] + psum[i - 1];
    }

    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n1, &n2);
        printf("Case #%d\n%d\n", tc, psum[n2] - psum[n1 - 1]);
    }

    return 0;
}