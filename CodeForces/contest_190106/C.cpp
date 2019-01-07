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

char in[201], res[201];
int main(int argc, char *argv[]) {
    int k, len, len2, c = 0, s = 0, i, idx;
    scanf("%s %d", in, &k);
    len = strlen(in);

    for (i = 0; i < len; ++i) {
      if (in[i] == '?') {
        ++c;
      } else if (in[i] == '*') {
        ++s;
      }
    }
    len = len - s - c;
    len2 = strlen(in); idx = 0;
    if ((len - s - c <= k && k <= len) || (s && k > len - s - c)) {
      for (i = 0; i < len2; ++i) {
        if (in[i] == '?') {
          if (k < len) {
            --idx;
            --len;
          }
        } else if (in[i] == '*') {
          if (k < len) {
            --idx;
            --len;
          } else if (k > len) {
            while (k > len) {
              res[idx++] = in[i-1];
              ++len;
            }
          }
        } else res[idx++] = in[i];
      }
      res[idx] = 0;
      printf("%s\n", res);
    } else printf("Impossible\n");

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