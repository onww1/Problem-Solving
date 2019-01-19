#include <cstdio>
using namespace std;

char in[50][5][8];
int main(int argc, char *argv[]) {
  int n, i, j, r, c;
  int mnx = 0, mny = 1, mnd = 0x7f7f7f7f;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) for (j = 0; j < 5; ++j) scanf(" %s", in[i][j]);
  for (i = 0; i < n-1; ++i) {
    for (j = i + 1; j < n; ++j) {
      int diff = 0;
      for (r = 0; r < 5; ++r) {
        for (c = 0; c < 7; ++c) {
          if (in[i][r][c] != in[j][r][c]) ++diff;
        }
      }
      if (diff < mnd) {
        mnd = diff;
        mnx = i;
        mny = j;
      }
    }
  }
  return !printf("%d %d\n", mnx + 1, mny + 1);
}