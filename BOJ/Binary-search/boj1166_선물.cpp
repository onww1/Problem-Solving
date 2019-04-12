#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef long double ldb;

const ldb ERR = 1e-10;
ll N, L, W, H;

int main(int argc, char *argv[]) {
    scanf("%lld %lld %lld %lld\n", &N, &L, &W, &H);
    ldb left = 0.0, right = 1e9, mid = 1e9, ans = 1e9;
    while (abs(right - left) > ERR) {
        mid = (left + right) / 2;
        ll cnt = (ll)(L / mid) * (ll)(W / mid) * (ll)(H / mid);
        if (cnt >= N) {
            ans = mid;
            left = mid;
        } else right = mid;
    }

    printf("%.12Lf\n", ans);
    return 0;
}