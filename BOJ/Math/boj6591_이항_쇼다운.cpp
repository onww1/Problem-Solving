#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 2147483647LL
using namespace std;

typedef long long ll;

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

ll fac[100001] = {1LL}, inv[100001] = {1LL};
int main(int argc, char *argv[]) {
  ll n, k, i;
  
  for (i = 1; i <= 100000; ++i) {
    fac[i] = i * fac[i-1] % MOD;
  }
  inv[100000] = get_pow(fac[100000], MOD - 2);
  for (i = 100000; i > 0; --i) {
    inv[i-1] = i * inv[i] % MOD;
  }

  while (true) {
    scanf("%lld %lld", &n, &k);
    if (!n && !k) break;
    if (k == 0 || k == n) printf("1\n");
    else if (k == 1 || k == n-1) printf("%lld\n", n);
    else {
      printf("%lld\n", (fac[n] * inv[k] % MOD) * inv[n-k] % MOD);
    }
  }

  return 0;
}