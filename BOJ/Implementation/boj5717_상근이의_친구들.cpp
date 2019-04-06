#include <cstdio>
using namespace std;

int main() {
  int m, f;
  while (1) {
    scanf("%d %d", &m, &f);
    if (m || f) printf("%d\n", m+f);
    else break;
  }
  return 0;
}