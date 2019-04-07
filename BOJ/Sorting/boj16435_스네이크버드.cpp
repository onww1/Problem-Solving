#include <cstdio>
#include <algorithm>
using namespace std;

int a[1050];
int main(int argc, char *argv[]) {
  int n, l, i;
  scanf("%d %d", &n, &l);
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  for (i = 0; i < n; ++i) 
    if (l + i < a[i]) return !printf("%d\n", l + i);
  return !printf("%d\n", l + n);
}