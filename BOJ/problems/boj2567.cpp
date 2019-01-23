#include <cstdio>
using namespace std;

bool check(int r, int c) { return 0 <= r && r < 100 && 0 <= c && c < 100; }
int move_r[] = {-1, 1, 0, 0}, move_c[] = {0, 0, -1, 1};
bool occupied[100][100];
int main(int argc, char *argv[]) {
  int n, i, j, k, a, b;
  scanf("%d", &n);
  for (k = 0; k < n; ++k) {
    scanf("%d %d", &a, &b);
    for (i = a; i < a + 10; ++i) for (j = b; j < b + 10; ++j) occupied[i][j] = true;
  }
  int len = 0, dr, dc;
  for (i = 0; i < 100; ++i) {
    for (j = 0; j < 100; ++j) {
      if (occupied[i][j]) {
        for (k = 0; k < 4; ++k) {
          dr = i + move_r[k];
          dc = j + move_c[k];
          if (!check(dr, dc) || !occupied[dr][dc]) ++len;
        }
      }
    }
  }
  return !printf("%d\n", len);
}