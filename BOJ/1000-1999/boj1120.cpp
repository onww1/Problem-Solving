#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[51], b[51];
int main(int argc, char *argv[]) {
  int l1, l2, i, j, mn = 1e9, cnt;
  scanf("%s %s", a, b);
  l1 = strlen(a);
  l2 = strlen(b);
  for (i = 0; i < l2 - l1 + 1; ++i) {
    cnt = 0;
    for (j = 0; j < l1; ++j) {
      if (a[j] != b[i+j]) ++cnt;
    }
    mn = min(mn, cnt);
  }
  return !printf("%d\n", mn);
}