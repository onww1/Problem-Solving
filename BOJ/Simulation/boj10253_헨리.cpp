#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b) { return b ? _gcd(b, a % b) : a; }
ll t, a, b;

int main(int argc, char *argv[]) {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &a, &b);
        ll x = 1LL;
        while (a > 1LL) {
            ll l = x + 1LL, r = 0x7fffffff, m = r;
            while (l <= r) {
                m = (l + r) >> 1;
                if (b > a * m) {
                    x = m;
                    l = m + 1;
                } else r = m - 1;
            }
            x++;
            ll nu = a * x - b, de = b * x;
            ll GCD = _gcd(nu, de);
            a = nu / GCD, b = de / GCD;
        }
        printf("%lld\n", b);
    } 
    return 0;
}