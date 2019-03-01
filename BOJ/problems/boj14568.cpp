#include <cstdio>
int main(int argc, char *argv[]) {
  int N, ans = 0;
  scanf("%d", &N);
  for (int i = 2; i <= N - 4; i += 2) 
    ans += (N - i - 2) / 2;
  return !printf("%d\n", ans);
}