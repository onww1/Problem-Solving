#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 998244353LL
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

ll fac[1000001] = {1LL, };
ll inv[1000001] = {1LL, };

int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);

  for (i = 1; i <= n; ++i) {
    fac[i] = fac[i-1] * i % MOD;
  }
  inv[n] = get_pow(fac[n], MOD-2LL);
  for (i = n; i > 0; --i) {
    inv[i-1] = inv[i] * i % MOD;
  }

  ll cnt = fac[n];
  for (i = 1; i < n-1; ++i) {
    cnt += (((fac[n] * inv[i-1] % MOD) * (fac[i] * inv[i+1] % MOD) % MOD) * (n - i - 1) % MOD);
    cnt %= MOD;
  }  

  printf("%lld\n", cnt);
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


// 1 2 3 4 
// 1 2 4 3 > 1
// 1 3 2 4 > 2
// 1 3 4 2 > 1
// 1 4 2 3 > 2
// 1 4 3 2 > 1
// 2 1 3 4 > 3
// 2 1 4 3 > 1
// 2 3 1 4 > 2
// 2 3 4 1 > 1
// 2 4 1 3 > 2
// 2 4 3 1 > 1
// 3 1 2 4 > 3
// 3 1 4 2 > 1
// 3 2 1 4 > 2
// 3 2 4 1 > 1
// 3 4 1 2 > 2
// 3 4 2 1 > 1
// 4 1 2 3 > 3
// 4 1 3 2 > 1
// 4 2 1 3 > 2
// 4 2 3 1 > 1
// 4 3 1 2 > 2
// 4 3 2 1 > 1

// 3 8 12


// 1 2 3
// 1 3 2 > 1
// 2 1 3 > 2
// 2 3 1 > 1
// 3 1 2 > 2
// 3 2 1 > 1

// 1 2
// 2 1 > 1

// 1 * 3 * 4 * 5 >> 5! / (1+ 1)
// 2 * 4 * 5     >> 5! / (2 + 1)
// 3 * 5
// 4 * 6