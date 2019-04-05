#include <cstdio>
int main(int argc, char *argv[]) {
  int n, k; scanf("%d", &n);
  return !printf("%d\n", n * (n - 1) * (n - 2) * (n - 3) / 24);
}
