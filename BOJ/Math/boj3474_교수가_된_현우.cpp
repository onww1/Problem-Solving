#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int t, n, s = 0;
  scanf("%d", &t);
  while (t--) {
    s = 0;
    scanf("%d", &n);
    while (n > 0) n /= 5, s += n;
    printf("%d\n", s);
  }
  return 0;
}