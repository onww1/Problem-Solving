#include <cstdio>
using namespace std;
const int SIZE = 100;

char map[SIZE][SIZE + 1];
int main(int argc, char *argv[]) {
  int t, i, j, k, len;
  for (int test_case = 1; test_case <= 10; ++test_case) {
    scanf("%d", &t);
    for (i = 0; i < SIZE; ++i) scanf(" %s", map[i]);
    bool found = false;
    for (len = SIZE; !found && len > 0; --len) {
      for (i = 0; !found && i < SIZE; ++i) {
        for (j = 0; !found && j < SIZE - len + 1; ++j) {
          // horizontal
          for (k = 0; k < len / 2; ++k) 
            if (map[i][j + k] != map[i][j + len - 1 - k]) break;
          if (k == len / 2) found = true;
          // vertical
          for (k = 0; k < len / 2; ++k) 
            if (map[i + k][j] != map[i + len - 1 - k][j]) break;
          if (k == len / 2) found = true;
        }
      }
    }
    printf("#%d %d\n", test_case, len + 1);
  }
}