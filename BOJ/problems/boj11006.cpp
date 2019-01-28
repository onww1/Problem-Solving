#include <cstdio>
int main(int argc, char *argv[]) {
  int t, n, m, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    printf("%d %d\n", 2 * m - n, n - m);
  }
  return 0;
}