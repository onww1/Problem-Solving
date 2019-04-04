#include <cstdio>
int main(int argc, char *argv[]) {
  int b, k, a, i, cnt = 0; 
  scanf("%d %d", &b, &k);
  for (i = 0; i < k; ++i) {
    scanf("%d", &a);
    if (a % 2) cnt++;
  }
  if (b % 2) return !printf("%s\n", cnt % 2 ? "odd" : "even");
  else return !printf("%s\n", a % 2 ? "odd" : "even");
}