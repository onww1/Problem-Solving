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
    int n, m, i, j, len, max_val = 1;
    char map[50][51];
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) scanf(" %s", map[i]);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        len = get_min(n - i, m - j);
        while (len > max_val) {
          if (map[i][j] == map[i + len - 1][j + len - 1] &&
              map[i][j] == map[i + len - 1][j] &&
              map[i][j] == map[i][j + len - 1]) max_val = len;
          else --len;
        }
      }
    }
    printf("%d\n", max_val * max_val);
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