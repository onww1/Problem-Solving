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
    int n, i, j, len;
    char str[201];
    bool valid[200], prev;
    scanf("%d", &n);

    while (n--) {
      scanf(" %s", str);
      len = strlen(str);
      memset(valid, false, len);

      prev = true;
      for (i = 0; i < len; ++i) {
        if (i > 0) prev = valid[i-1];
        if (prev) {
          if (str[i] == '0') {
            if (i + 1 < len && str[i + 1] == '1') 
              valid[i + 1] = true;
          } else if (str[i] == '1') {
            if (i + 2 < len && str[i+1] == '0' && str[i+2] == '0') {
              j = i + 3;
              while (j < len && str[j] == '0') ++j;
              while (j < len && str[j] == '1') valid[j] = true, ++j;
            } else continue;
          }
        }
      }

      if (valid[len - 1]) printf("YES\n");
      else printf("NO\n");
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