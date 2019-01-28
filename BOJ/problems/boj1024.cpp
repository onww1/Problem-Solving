#include <cstdio>
typedef long long ll;

int main(int argc, char *argv[]) {
  ll n, l, i, j, a;
  scanf("%lld %lld", &n, &l);
  n *= 2LL;
  if (l * (l-1) == n) {
    for (j = 0; j < l; ++j) printf("%lld ", j);
      return !printf("\n");
  }

  for (i = l; i * i < n && i < 101; ++i) {
    if (n % i == 0 && (n / i - i + 1) % 2 == 0) {
      a = (n / i - i + 1) / 2;
      for (j = 0; j < i; ++j) printf("%lld ", a + j);
      return !printf("\n");
    }
  }
  return !printf("-1\n");
}
