#include <cstdio>
int main(int argc, char *argv[]) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  return !printf("%d\n", c-b <= 0 ? -1 : a / (c-b) + 1);
}
