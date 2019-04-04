#include <cstdio>
int main(int argc, char *argv[]) {
  int a, b, c, sum = 0;
  scanf("%d %d %d", &a, &b, &c);
  b += a * 7;
  sum = 7 * (c / b);
  c %= b;
  if (c / a > 6) sum += 7;
  else sum += (c/a + (c%a > 0));
  return !printf("%d\n", sum);
}