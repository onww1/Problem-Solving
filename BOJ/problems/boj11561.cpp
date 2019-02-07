#include <cstdio>
typedef long long ll;

int main(int argc, char *argv[]) {
  ll t, n;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    ll s = 1, e = 2e8, m;
    while (s < e) {
      m = (s + e) / 2;
      if (m * (m + 1) > 2LL * n) e = m;
      else s = m + 1;
    }
    printf("%lld\n", s * (s + 1) > 2LL * n ? s - 1 : s);
  }
  return 0;
}