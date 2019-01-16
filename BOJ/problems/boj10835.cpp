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

// #include <cstdio>
// #include <algorithm>
// #define INF 0x7f7f7f7f
// using namespace std;

// int a[2050], b[2050], dp[2050][2050];
// int main(int argc, char *argv[]) {
//   int n, i, j, mx = 0;
//   scanf("%d", &n);
//   for (i = 1; i <= n; ++i) scanf("%d", a + i);
//   for (i = 1; i <= n; ++i) scanf("%d", b + i);
//   b[0] = INF;
//   for (j = 1; j <= n; ++j) {
//     for (i = 1; i <= n; ++i) {
//       if (a[i] > b[j]) dp[i][j] = dp[i][j-1] + b[j];
//       else {
//         dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
//         if (a[i] > b[j-1]) dp[i][j] = max(dp[i][j], dp[i][j-1]);
//       }
//       mx = max(mx, dp[i][j]);
//     }
//   }
//   return !printf("%d\n", mx);
// }