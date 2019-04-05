#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {
  double in;
  while (true) {
    scanf("%lf", &in);
    if (abs(in - 0.0) <= 1e-9) break;
    printf("%.2lf English miles equals %.2lf Roman miles or %d paces.\n", in, in * 5280 / 4854, (int)round(in * 5280 / 4854 * 1000));
  }
  return 0;
}