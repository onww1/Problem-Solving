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
    int n, i, j, org[50], sorted[50];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &org[i]), sorted[i] = org[i];
    sort(sorted, sorted + n);

    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (org[i] == sorted[j]) {
          printf("%d ", j);
          sorted[j] = -1;
          break;
        }
      }
    }
    putchar('\n');

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
