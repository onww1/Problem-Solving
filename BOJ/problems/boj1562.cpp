#include <cstdio>
#include <cstring>
typedef long long ll;

const int MOD = 1e9;
int DP[101][10][1 << 10], n, ans;

int solve(int len, int num, int mask) {
  int &ret = DP[len][num][mask];
  mask = mask | (1 << num);

  if (num < 0 || num > 9) return 0;
  if (len == n) return (mask == (1 << 10) - 1) ? 1 : 0;
  if (ret != -1) return ret;

  return ret = ((ll)solve(len + 1, num - 1, mask) + solve(len + 1, num + 1, mask)) % MOD;
}

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  memset(DP, -1, sizeof(DP));
  for (int i = 1; i <= 9; ++i)
    ans = ((ll)ans + solve(1, i, 0)) % MOD;
  return !printf("%d\n", ans);
}