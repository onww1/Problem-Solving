#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000000], b[1000000], res[2000000];
int main(int argc, char *argv[]) {
  int n, m, i, j, p;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  for (i = 0; i < m; ++i) scanf("%d", b + i);
  sort(a, a+n); sort(b, b+m);
  i = j = p = 0;
  while (i < n && j < m) {
    if (a[i] < b[j]) res[p++] = a[i++];
    else if (a[i] > b[j]) res[p++] = b[j++];
    else {
      res[p++] = a[i++];
      res[p++] = b[j++];
    }
  }
  while (i < n) res[p++] = a[i++];
  while (j < m) res[p++] = b[j++];
  for (i = 0; i < n + m; ++i) printf("%d ", res[i]);
  return !printf("\n");
}