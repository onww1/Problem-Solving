#include <cstdio>
typedef long long ll;

int N, ans, A[1000][1000];
ll tot;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", A[i] + j);
            tot += A[i][j];
        }
    }
  
    int l = 0, r = 10000000;
    while (l <= r) {
        int m = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] > m) cnt += m;
                else cnt += A[i][j];
            }
        }
        if (cnt >= (tot + 1LL) / 2LL) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}