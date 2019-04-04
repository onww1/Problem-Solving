#include <cstdio>
const int MAX = 1e6;

int arr[MAX + 1];
int main(int argc, char *argv[]) {
  int n, a, i, idx;
  bool f = true, b = true;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a);
    arr[a] = i;
  }
  scanf("%d", &a); idx = arr[a];
  for (i = 1; i < n; ++i) {
    scanf("%d", &a);
    if (arr[a] != (idx + n - 1) % n) b = false;
    if (arr[a] != (idx + 1) % n) f = false;
    idx = arr[a];
  }
  if (!f && !b) return !printf("bad puzzle\n");
  return !printf("good puzzle\n");
}