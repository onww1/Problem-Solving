#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {
  int d, h, w;
  scanf("%d %d %d", &d, &h, &w);
  double ratio = sqrt((double)d*d / (h*h + w*w));
  return !printf("%d %d\n", (int)(floor(ratio * h)), (int)(floor(ratio * w)));
}