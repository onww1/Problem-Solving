#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int q, l1, r1, l2, r2, i;
  scanf("%d", &q);
  for (i = 0; i < q; ++i) {
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    if (r1 != l2) printf("%d %d\n", r1, l2);
    else if (r1 != r2) printf("%d %d\n", r1, r2);
    else if (l1 != l2) printf("%d %d\n", l1, l2);
    else if (l1 != r2) printf("%d %d\n", l1, r2);
  }
  return 0;
}