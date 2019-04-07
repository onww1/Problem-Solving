#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int move_r[] = {1, 0, -1, 0};
const int move_c[] = {0, 1, 0, -1};

int main(int argc, char *argv[]) {
  int n, r = 0, c = 0;
  scanf("%d", &n);
  for (int len = 1; n > 0; ++len) {
    for (int i = 0; i < len && n > 0; ++i, n--) {
      r += move_r[0 + (1 - len % 2) * 2];
      c += move_c[0 + (1 - len % 2) * 2];
    }
    for (int i = 0; i < len && n > 0; ++i, n--) {
      r += move_r[1 + (1 - len % 2) * 2];
      c += move_c[1 + (1 - len % 2) * 2];
    }
  }

  return !printf("%d %d\n", c, r);
}