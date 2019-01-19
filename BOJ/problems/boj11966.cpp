#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int n; scanf("%d", &n);
  return !printf("%d\n", n == (n & -n) ? 1 : 0);
}