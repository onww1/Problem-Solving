#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  double x, y, c;
  scanf("%lf %lf %lf", &x, &y, &c);
  double s = 0, e = min(x, y), m;
  while (true) {
    m = (s + e) / 2.0;
    double tmp = c * (1.0 / sqrt(x * x - m * m) + 1.0 / sqrt(y * y - m * m));
    if (abs(tmp - 1.0) <= 1e-9) break;
    else if (tmp < 1.0) s = m;
    else e = m;
  }
  return !printf("%.3lf\n", m);
}