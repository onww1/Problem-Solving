#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 1e4 + 1;
int N, K, D, A[MAX], B[MAX], C[MAX];

bool solve(int m) {
    ll cnt = 0;
    for (int i = 0; i < K; ++i) {
        if (A[i] <= m) {
            cnt += (min(m, B[i]) - A[i]) / C[i] + 1;
        }
    }
    return cnt >= (ll)D;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &K, &D);
    for (int i = 0; i < K; ++i) scanf("%d %d %d", A + i, B + i, C + i);

    int lo = 1, hi = N, ans = hi;
    while (lo <= hi) {
        int m = (lo + hi) >> 1;
        if (solve(m)) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}