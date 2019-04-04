#include <cstdio>
int get_point(int x, int y) {
  int square_d = x * x + y * y;
  for (int i = 10; i > 0; --i) {
    int dd = 10 * (2 * (11 - i) - 1);
    if (square_d <= dd * dd) return i;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int sum = 0, x, y, n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &x, &y);
    sum += get_point(x, y);
  }
  return !printf("%d\n", sum);
}