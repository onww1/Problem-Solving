#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[1050], dp[1050];
int main() {
  int n, i, j, mx, mn;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  for (i = 2; i <= n; ++i) {
    mx = a[i], mn = a[i];
    for (j = i; j > 0; --j) {
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
      dp[i] = max(dp[i], dp[j-1] + mx - mn);
    }
  }
  return !printf("%d\n", dp[n]);
}