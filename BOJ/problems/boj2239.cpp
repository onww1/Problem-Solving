#include <cstdio>
bool visited[3][9][10];
char map[9][10];

int sector(int r, int c) { return 3 * (r / 3) + c / 3; }
bool possible(int r, int c, int n) {
  bool p = false;
  p = p || visited[0][r][n];
  p = p || visited[1][c][n];
  p = p || visited[2][sector(r, c)][n];
  return !p;
}
void fill(int r, int c, int n, bool v) {
  visited[0][r][n] = v;
  visited[1][c][n] = v;
  visited[2][sector(r, c)][n] = v;
}

bool solve(int r, int c) {
  while (r < 9 && map[r][c] != '0') {
    ++c;
    if (c == 9) r++, c = 0;
  }
  if (r == 9) return true;
  for (int k = 1; k < 10; ++k) {
    if (possible(r, c, k)) {
      fill(r, c, k, true);
      map[r][c] += k;
      if (solve(r, c)) return true;
      fill(r, c, k, false);
      map[r][c] -= k;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  for (i = 0; i < 9; ++i) scanf(" %s", map[i]);
  for (i = 0; i < 9; ++i) {
    for (j = 0; j < 9; ++j) {
      if (map[i][j] != '0') {
        visited[0][i][map[i][j] - '0'] = true;
        visited[1][j][map[i][j] - '0'] = true;
        visited[2][sector(i, j)][map[i][j] - '0'] = true;
      }
    }
  }
  solve(0, 0);
  for (i = 0; i < 9; ++i) printf("%s\n", map[i]);
  return 0;
}