#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 1000;
const ll MOD = 1000000007LL;
int T, N, K;
ll fac[MAX + 1] = {1}, inv[MAX + 1];

ll _pow(ll base, ll exp) {
  ll ret = 1;
  while (exp) {
    if (exp % 2LL) ret = ret * base % MOD;
    base = base * base % MOD;
    exp /= 2LL;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  for (ll i = 1; i <= 1000; ++i) fac[i] = fac[i - 1] * i % MOD;
  inv[MAX] = _pow(fac[MAX], MOD - 2);
  for (ll i = 1000; i > 0; --i) inv[i - 1] = i * inv[i] % MOD;

  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &K);
    printf("%lld\n", fac[N] * (inv[N - K] * inv[K] % MOD) % MOD);
  }
  return 0;
}