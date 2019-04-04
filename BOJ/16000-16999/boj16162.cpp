#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int n, a, d, in, x = 0, i;
  scanf("%d %d %d", &n, &a, &d);
  for (i = 0; i < n; ++i) {
    scanf("%d", &in);
    if (in == a + x * d) ++x;
  }
  return !printf("%d\n", x);
}