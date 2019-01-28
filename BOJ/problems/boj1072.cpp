#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int x, y, ratio;
  scanf("%d %d", &x, &y);
  ratio = 100LL * y / x;
  if (ratio >= 99) return !printf("-1\n");

  int s = 1, e = x+1, m, r;
  while (s < e) {
    m = (s + e) / 2;
    r = 100LL * (y + m) / (x + m);
    if (r == ratio) s = m + 1;
    else e = m;
  }
  return !printf("%d\n", e);
}

