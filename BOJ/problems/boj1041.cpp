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
    ll n, a[6], min_val[3] = {INF, INF, INF}, ans = 0;
    int i, j, k;
    scanf("%lld", &n);
    for (i = 0; i < 6; ++i) {
      scanf("%lld", &a[i]);
      min_val[0] = get_min(min_val[0], a[i]);
    }

    if (n == 1LL) {
      sort(a, a+6);
      for (i = 0; i < 5; ++i) ans += a[i];
      printf("%lld\n", ans);
    } else {
      for (i = 0; i < 6; ++i) {
        for (j = i + 1; j < 6; ++j) {
          if (j != 5 - i) {
            min_val[1] = get_min(min_val[1], a[i] + a[j]);
            for (k = j + 1; k < 6; ++k) {
              if (k != 5 - i && k != 5 - j) {
                min_val[2] = get_min(min_val[2], a[i] + a[j] + a[k]);
              }
            }
          }
        }
      }

      ans = ans + min_val[0] * ((n-2)*(n-1)*4 + (n-2)*(n-2));
      ans = ans + min_val[1] * ((n-1)*4 + (n-2)*4);
      ans = ans + min_val[2] * 4;
      printf("%lld\n", ans);
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