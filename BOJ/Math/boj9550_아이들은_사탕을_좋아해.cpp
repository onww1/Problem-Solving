#include <cstdio>
int main(int argc, char *argv[]) {
  int t, n, k, a, cnt, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    cnt = 0;
    for (i = 0; i < n; ++i) {
      scanf("%d", &a);
      cnt += (a / k);
    }
    printf("%d\n", cnt);
  }
  return 0;
}