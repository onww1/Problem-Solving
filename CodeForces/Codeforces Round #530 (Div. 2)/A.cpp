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
    int w, h, u[2], d[2], i;
    scanf("%d %d", &w, &h);
    for (i = 0; i < 2; ++i) scanf("%d %d", &u[i], &d[i]);

    for (i = h; i > 0; --i) {
      w += i;
      if (i == d[0]) w = w < u[0] ? 0 : w - u[0];
      else if (i == d[1]) w = w < u[1] ? 0 : w - u[1];
    }

    printf("%d\n", w);
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