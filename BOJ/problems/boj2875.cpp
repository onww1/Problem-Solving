#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  int n, m, k, t;
  scanf("%d %d %d", &n, &m, &k);
  t = min(n/2, m);
  k -= (n + m - 3 * t);
  while (k > 0) {
    --t; k -= 3;
  }
  return !printf("%d\n", t > 0 ? t : 0);
}