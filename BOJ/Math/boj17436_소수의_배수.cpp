#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, m, ans, a[10];

int main(int argc, char *argv[]) {
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%lld", a + i);

    int lim = 1 << n;
    for (int i = 1; i < lim; ++i) {
        ll val = 1LL, cnt = 0LL;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt++;
                val *= a[j];
            }
        }
        if (cnt % 2) ans += (m / val);
        else ans -= (m / val);
    }

    printf("%lld\n", ans);
    return 0;
}