#include <cstdio>
const int MAX = 1e6;
const int MOD = 1e9;

int DP[MAX + 1];
int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  DP[0] = 1;
  for (j = 1; j <= n; j *= 2) 
    for (i = 1; i <= n; ++i) 
      if (i >= j) DP[i] = (DP[i] + DP[i - j]) % MOD;
  return !printf("%d\n", DP[n]);
}