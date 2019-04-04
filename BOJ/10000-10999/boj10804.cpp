#include <cstdio>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char *argv[]) {
  int a[21], l, r, i, j;
  for (i = 1; i <= 20; ++i) a[i] = i;
  for (i = 0; i < 10; ++i) {
    scanf("%d %d", &l, &r);
    for (j = 0; j < (r - l + 1) / 2; ++j) {
      swap(a[l + j], a[r - j]);
    }
  }
  for (i = 1; i <= 20; ++i) printf("%d ", a[i]);
  return !printf("\n");
}