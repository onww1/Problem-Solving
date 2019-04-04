#include <cstdio>

long long cal(long long n, long long len) {
  long long ret = 1LL;
  for (long long i = 0; i < len; ++i) {
    ret *= (n % 10);
    n /= 10;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  long long n;
  scanf("%lld", &n);

  long long tmp = n, len = 0;
  while (tmp) { len++; tmp /= 10; }
  for (long long i = 10, j = 1; n / i > 0; i *= 10, j++) {
    long long front = n / i;
    long long back = n % i;
    if (cal(front, len - j) == cal(back, j)) return !printf("YES\n");
  }
  return !printf("NO\n");
}