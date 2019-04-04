#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 1000000007LL
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int main(int argc, char *argv[]) {
  int y, b, r;
  scanf("%d %d %d", &y, &b, &r);
  int min_val = get_min(get_min(y, b-1), r-2);
  printf("%d\n", min_val * 3 + 3);
  return 0;
}

ll get_pow(ll base, ll exp) {
  ll ret = 1;
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
