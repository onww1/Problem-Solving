#include <cstdio>
const int MAX = 1e6;
const int MOD = 1e9;
int DP[MAX / 2 + 1];

int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  DP[0] = 1;
  for (i = 1; i <= n / 2; ++i) DP[i] = (DP[i-1] + DP[i/2]) % MOD;
  return !printf("%d\n", DP[n/2]);
}