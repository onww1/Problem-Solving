#include <cstdio>
#include <cstring>
using namespace std;

char in[21], ans[21];
int main(int argc, char *argv[]) {
  int t, n, i, mx, d;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    mx = 0;
    for (i = 0; i < n; ++i) {
      scanf(" %s %d", in, &d);
      if (d > mx) {
        mx = d;
        strcpy(ans, in);
      }
    }
    printf("%s\n", ans);
  }
  return 0;
}