#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    ll X, Y;
    scanf("%lld %lld", &X, &Y);
    Y -= X;

    ll l = 0, r = 1LL << 16, m = r, v = r;
    while (l <= r) {
        m = (l + r) >> 1;
        if (m * (m + 1) <= Y) {
            v = m;
            l = m + 1;
        } else r = m - 1;
    }

    ll ans = 2 * v;
    Y -= v * (v + 1);
    if (Y > v + 1) ans += 2;
    else if (Y > 0) ans += 1;

    printf("%lld\n", ans);
    return 0;
}