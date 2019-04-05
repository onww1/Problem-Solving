#include <cstdio>

int main(int argc, char *argv[]) {
  int a, b, c[22][22], i, j;
  for (i = 0; i < 22; ++i) c[i][i] = c[i][0] = 1;
  for (i = 2; i < 22; ++i) for (j = 1; j < i; ++j) c[i][j] = c[i-1][j] + c[i-1][j-1];
  while (true) {
    scanf("%d %d", &a, &b);
    if (a == -1 && b == -1) break;
    printf("%d+%d%s%d\n", a, b, c[a + b][b] == a+b ? "=" : "!=", a + b);
  }  
  return 0;
}