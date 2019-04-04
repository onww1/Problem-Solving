#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int t, v, e;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &v, &e);
    printf("%d\n", 2 - v + e);
  }
  return 0;
}