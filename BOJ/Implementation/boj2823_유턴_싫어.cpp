#include <cstdio>
using namespace std;

char in[12][12];
int r, c, move_r[4] = {-1, 1, 0, 0}, move_c[] = {0, 0, -1, 1};

bool check(int R, int C) {
  return !(R < 0 || R > r || C < 0 || C > c);
}

int main(int argc, char *argv[]) {
  int i, j, k, cnt, dr, dc;
  scanf("%d %d", &r, &c);
  for (i = 0; i < r; ++i) scanf(" %s", in[i]);
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      if (in[i][j] == '.') {
        for (cnt = 0, k = 0; k < 4; ++k) {
          dr = i + move_r[k];
          dc = j + move_c[k];
          if (check(dr, dc) && in[dr][dc] == '.') ++cnt;
        }
        if (cnt <= 1) return !printf("1\n");
      }
    }
  }
  return !printf("0\n");
}