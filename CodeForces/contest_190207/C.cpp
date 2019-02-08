#include <cstdio>
int main(int argc, char *argv[]) {
  int q, a, i, j;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &a);
    for (i = 2; i <= 25; ++i) {
      if (a == (1 << i) - 1) {
        for (j = 2; j * j <= a; ++j) {
          if (a % j == 0) {
            printf("%d\n", a / j);
            break;
          }
        }
        if (j * j > a) printf("1\n");
        break;
      } else if (a < (1 << i)) {
        printf("%d\n", (1 << i) - 1);
        break;
      }
    }
  }
  return 0;
}