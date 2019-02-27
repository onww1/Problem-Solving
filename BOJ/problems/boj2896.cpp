#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  int a, b, c, i, j, k;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &i, &j, &k);

  double r1 = (double)a / i;
  double r2 = (double)b / j;
  double r3 = (double)c / k;
  double mn = min({r1, r2, r3});
  printf("%.6lf %.6lf %.6lf\n", a - i * mn, b - j * mn, c - k * mn);
}