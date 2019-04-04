#include <cstdio>
int main(int argc, char *argv[]) {
  long long fac = 1, n;
  scanf("%lld", &n);
  double res = 1.0;
  for (long long i = 1; i <= n && i <= 20; ++i) {
    fac *= i;
    res += (1.0 / fac);
  }
  printf("%.15lf\n", res);
  return 0;
}