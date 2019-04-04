#include <cstdio>
typedef long long ll;

int main(int argc, char *argv[]) {
  ll n, res = 0LL, mul = 1LL, i;
  scanf("%lld", &n);
  for (i = 0; i < 40; ++i, mul *= 3LL)
    if (n & (1LL << i)) res += mul;
  return !printf("%lld\n", res);
}
