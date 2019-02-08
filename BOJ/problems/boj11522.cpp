#include <cstdio>
int main(int argc, char *argv[]) {
  int t, a, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &n);
    printf("%d %d %d %d\n", a, n * (n + 1) / 2, n * n, n * (n + 1));
  }
  return 0;
}