#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);

int in[100050];
int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  ll sum = (ll)n * (ll)(n + 1) / 2LL;
  return !printf("%lld\n", sum % 2LL);
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
