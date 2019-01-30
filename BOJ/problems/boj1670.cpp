#include <cstdio>
const int MOD = 987654321;

int DP[10005];
int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  DP[0] = DP[2] = 1;
  for (i = 4; i <= n; i += 2) {
    for (j = 0; j < (i-2)/2; j += 2) 
      DP[i] = (DP[i] + 2LL * DP[j] * DP[i - 2 - j]) % MOD;
    if (i % 4 == 2) DP[i] = (DP[i] + 1LL * DP[i / 2 - 1] * DP[i / 2 - 1]) % MOD;  
  }
  return !printf("%d\n", DP[n]);
}
