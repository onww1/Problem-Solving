#include <cstdio>

int main(int argc, char *argv[]) {
  int n, b; double p;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %lf", &b, &p);
    double bpm = 60 * b / p;
    double abpm = 60 / p;
    printf("%.4lf %.4lf %.4lf\n", bpm - abpm, bpm, bpm + abpm);
  }
  return 0;
}