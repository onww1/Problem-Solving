#include <cstdio>
const int MAX = 1e6;
const int MOD = 1e9;
int DP[MAX + 1][20];

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < 20; ++i) DP[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
      DP[i][0] = 1;
      for (int j = 1; j < 20; ++j) {
        if (i >= (1 << j))
          DP[i][j] = (DP[i][j-1] + DP[i - (1 << j)][j]) % MOD;
        else
          DP[i][j] = DP[i][j-1];
      }
  }
  return !printf("%d\n", DP[n][19]);
}