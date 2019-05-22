#include <cstdio>

int T, A, B, C;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &A, &B, &C);
        int lo = 0, hi = 141, ans = 0;
        while (lo <= hi) {
            int m = (lo + hi) >> 1;
            if (A + m * (m + 1) / 2 * C >= B) {
                ans = m;
                hi = m - 1;
            } else lo = m + 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}