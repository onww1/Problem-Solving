#include <cstdio>
using namespace std;

char ans[8][105];

void solve(int s, int e, char c, int T) {
  if (T == 8) return;
  for (int i = s; i < e; ++i) ans[T][i] = c;
  if (s + 1 == e) solve(s, e, c, T + 1);
  else {
    int m = (s + e) / 2;
    solve(s, m, 'A', T + 1);
    solve(m, e, 'B', T + 1);
  }
}

int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i <= 7; ++i) ans[i][n] = 0;
  solve(0, n, 'A', 0);
  for (i = 1; i <= 7; ++i) printf("%s\n", ans[i]);
  return 0;
}