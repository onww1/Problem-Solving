#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

ll get_pow(ll base, ll exp);

int main(int argc, char *argv[]) {
  ll q, l, r, d, i;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld %lld %lld", &l, &r, &d);
    if (d < l) {
      printf("%lld\n", d);
    } else {
      printf("%lld\n", (r + d) - (r + d) % d);
    }
  }
  return 0;
}

ll get_pow(ll base, ll exp) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2) {
      ret *= base;
      ret %= MOD;
    }
    base *= base;
    base %= MOD;
    exp /= 2LL;
  }
  return ret;
}