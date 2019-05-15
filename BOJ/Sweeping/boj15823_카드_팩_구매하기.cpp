#include <cstdio>

const int MAX = 1e5;
int N, M, A[MAX + 1], DP[MAX + 1];
int last[5 * MAX + 1];

bool solve(int len) {
    int cnt = 0;
    for (int i = N; i > 0;) {
        if (DP[i] >= len) {
            cnt += DP[i] / len;
            i -= DP[i] / len * len;
        } 
        else --i;
    }
    return cnt >= M;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", A + i);
        DP[i] = DP[i - 1] + 1;
        if (last[A[i]] > i - DP[i]) 
            DP[i] = i - last[A[i]];
        last[A[i]] = i;
    }
    
    int l = 1, r = N, m = r, ans = r;
    while (l <= r) {
        m = (l + r) >> 1;
        if (solve(m)) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }

    printf("%d\n", ans);
    return 0;
}