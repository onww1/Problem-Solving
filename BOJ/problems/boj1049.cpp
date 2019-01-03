#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define MOD 1000000007LL
#define INF 1023456789LL
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int main(int argc, char *argv[]) {
    int n, m, min_val = INF, a[50], b[50], i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
      scanf("%d %d", &a[i], &b[i]);
    }
    sort(a, a+m);
    sort(b, b+m);
    if (a[0] < b[0] * 6) {
      printf("%d\n", n / 6 * a[0] + (a[0] < n % 6 * b[0] ? a[0] : n % 6 * b[0]));
    } else {
      printf("%d\n", n * b[0]);
    }
    return 0;
}

ll get_pow(ll base, ll exp) {
    ll ret = 1LL;
    while (exp > 0) {
        if (exp % 2) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }