#include <cstdio>
typedef long long ll;

const int MAX = 1e5;
ll N, M, ans, T[MAX];

int main(int argc, char *argv[]) {
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%lld", T + i);

    ll l = 1, r = 1e13, m = 1;
    while (l <= r) {
        m = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; ++i) cnt += m / T[i];
        if (cnt >= M) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    printf("%lld\n", ans);
    return 0;
}