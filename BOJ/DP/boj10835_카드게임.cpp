/*
 *  1st method.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[2050], b[2050], dp[2050][2050], n;

int solve(int x, int y) {
  if (x == n || y == n) return 0;

  int &ret = dp[x][y];
  if (~ret) return ret;
  ret = max(solve(x + 1, y + 1), solve(x + 1, y));
  if (a[x] > b[y]) ret = max(ret, b[y] + solve(x, y + 1));
  return ret;
}

int main(int argc, char *argv[]) {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  for (i = 0; i < n; ++i) scanf("%d", b + i);
  memset(dp, -1, sizeof(dp));
  return !printf("%d\n", solve(0, 0));
}

/*
 *  2nd method.
 */

// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int a[2050], b[2050], dp[2050][2050];
// int main(int argc, char *argv[]) {
//   int n, i, j;
//   scanf("%d", &n);
//   for (i = n; i > 0; --i) scanf("%d", a + i);
//   for (i = n; i > 0; --i) scanf("%d", b + i);
//   for (i = 1; i <= n; ++i) {
//     for (j = 1; j <= n; ++j) {
//       dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
//       if (a[i] > b[j]) dp[i][j] = max(dp[i][j], dp[i][j-1] + b[j]);
//     }
//   }
//   return !printf("%d\n", dp[n][n]);
// }