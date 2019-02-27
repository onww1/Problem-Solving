#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char in[251];
int A, B, as, bs, i;

int main(int argc, char *argv[]) {
  while (1) {
    scanf(" %s", in);
    if (in[0] == '#') break;
    for (i = A = B = as = bs = 0; in[i]; ++i) {
      if (in[i] == 'A') A++;
      else B++;

      if (A >= 4 && A - B > 1) as++, A = B = 0;
      if (B >= 4 && B - A > 1) bs++, A = B = 0;
    }
    printf("A %d B %d\n", as, bs);
  }
  return 0;
}