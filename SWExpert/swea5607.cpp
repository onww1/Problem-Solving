#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e6;
const int MOD = 1234567891;
int fac[MAX + 1], inv[MAX + 1], t, n, r;

ll pow(ll base, ll exp) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2LL) ret = ret * base % MOD;
    base = base * base % MOD;
    exp /= 2LL;
  }
  return ret;
}

void init() {
  fac[0] = 1;
  for (int i = 1; i <= MAX; ++i) fac[i] = 1LL * fac[i-1] * i % MOD;
  inv[MAX] = pow(fac[MAX], MOD - 2);
  for (int i = MAX; i > 0; --i) inv[i-1] = 1LL * inv[i] * i % MOD;
}

int main(int argc, char *argv[]) {
  init();
  scanf("%d", &t);
  for (int test_case = 1; test_case <= t; ++test_case) {
    scanf("%d %d", &n, &r);
    printf("#%d %lld\n", test_case, fac[n] * (1LL * inv[r] * inv[n-r] % MOD) % MOD);
  }
  return 0;
}