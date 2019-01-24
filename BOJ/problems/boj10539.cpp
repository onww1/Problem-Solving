#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int n, b, s = 0, i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &b);
    printf("%d ", b * i - s);
    s = b * i;
  }
  return 0;
}