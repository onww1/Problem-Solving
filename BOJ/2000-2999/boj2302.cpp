#include <cstdio>
using namespace std;

int dp[41] = {1, 1, 2, };
int main(int argc, char *argv[]) {
  int n, m, vip[41], i, ans = 1;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; ++i) scanf("%d", vip + i);
  for (i = 3; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
  for (i = 1; i < m; ++i) ans *= dp[vip[i] - vip[i-1] - 1];
  if (m > 0) {
    ans *= dp[vip[0] - 1];
    ans *= dp[n - vip[m-1]];
  } else {
    ans = dp[n];
  }
  return !printf("%d\n", ans);
}