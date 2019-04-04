#include <cstdio>
#define MOD 10007
using namespace std;

int dp[1050];
int main() {
  int n, i;
  scanf("%d", &n);
  dp[0] = dp[1] = 1;
  for (i = 2; i <= n; ++i)
    dp[i] = (dp[i-1] + 2 * dp[i-2]) % MOD;
  return !printf("%d\n", dp[n]);
}