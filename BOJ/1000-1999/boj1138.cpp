#include <cstdio>
bool visited[11];
int p[11], a[11];
int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", p + i);
  for (i = 1; i <= n; ++i) {
    for (j = 1; p[i] || visited[j]; ++j)
      if (!visited[j]) p[i]--;
    visited[j] = true; a[j] = i;
  }  
  for (i = 1; i <= n; ++i) printf("%d ", a[i]);
  return !printf("\n");
}