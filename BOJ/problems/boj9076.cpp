#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  int t, a[5], i;
  scanf("%d", &t);
  while (t--) {
    for (i = 0; i < 5; ++i) scanf("%d", a + i);
    sort(a, a + 5);
    if (a[3] - a[1] > 3) printf("%s\n", "KIN");
    else printf("%d\n", a[1] + a[2] + a[3]);
  }
  return 0;
}