#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 123456;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
int N, IA, T[MAX], A[MAX], H[MAX];

bool solve(ll H_MX) {
    ll HA = IA, HP = H_MX;
    for (int i = 0; i < N; ++i) {
        if (T[i] == 1) {
            ll hero = (H[i] + HA - 1) / (ll)HA;
            ll mons = (HP + A[i] - 1) / (ll)A[i];
            if (hero > mons) return false;
            HP -= 1LL * A[i] * (hero - 1);
        }
        else {
            HA += A[i];
            HP = min(H_MX, HP + H[i]);
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &IA);
    for (int i = 0; i < N; ++i) 
        scanf("%d %d %d", T + i, A + i, H + i);

    ll lo = 1, hi = LL_INF, ans = hi;
    while (lo <= hi) {
        ll m = (lo + hi) >> 1;
        if (solve(m)) {
            ans = m;
            hi = m - 1;
        } else lo = m + 1;
    }
    
    printf("%lld\n", ans);
    return 0;
}