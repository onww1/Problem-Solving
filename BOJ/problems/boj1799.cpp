#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10;

int map[MAX][MAX], n, visited[20];

void solve(int T, int cur, int &mx) {
  if (T == 2 * n - 1) {
    mx = max(mx, cur);
    return;
  }

  bool empty = true;
  int diff = T + 1 - n;
  for (int i = 0, j; i < n; ++i) {
    j = i - T - 1 + n;
    if (0 <= j && j < n && !visited[i + j] && map[i][j]) {
      empty = false;
      visited[i + j] = true;
      solve(T + 1, cur + 1, mx);
      visited[i + j] = false;
    }
  }
  
  if (empty) solve(T + 1, cur, mx);
}

int main(int argc, char *argv[]) {
  int i, j, mx = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) scanf("%d", &map[i][j]);
  solve(0, 0, mx);
  return !printf("%d\n", mx);
}