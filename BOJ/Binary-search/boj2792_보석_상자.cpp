#include <cstdio>
typedef long long ll;

const int MAX = 3e5 + 1;
int N, M, A[MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) scanf("%d", A + i);

    int lo = 1, hi = 1e9, ans = hi;
    while (lo <= hi) {
        int m = (lo + hi) >> 1;
        ll cnt = 0;
        for (int i = 0; i < M; ++i) 
            cnt += (A[i] + m - 1) / m;
        if (cnt <= (ll)N) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}