#include <cstdio>
int main(int argc, char *argv[]) {
  int n, i, ans = 0;
  scanf("%d", &n);
  for (i = 44721; n > 0 && i > 0;) {
    if (n >= i * (i + 1) / 2) {
      ans += i;
      n -= i * (i + 1) / 2;
    } else --i;
  }
  return !printf("%d\n", ans);
}