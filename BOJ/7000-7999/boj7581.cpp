#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  int a, b, c, d;
  while (1) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (!a && !b && !c && !d) break;
    if (!a) printf("%d %d %d %d\n", d / b / c, b, c, d);
    if (!b) printf("%d %d %d %d\n", a, d / a / c, c, d);
    if (!c) printf("%d %d %d %d\n", a, b, d / a / b, d);
    if (!d) printf("%d %d %d %d\n", a, b, c, a * b * c);
  }
  return 0;
}