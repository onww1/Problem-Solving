#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[101][100][2];
int main(int argc, char *argv[]) {
  int t, n, k, i, j;
  DP[1][0][1] = DP[1][0][0] = 1;
  for (i = 2; i <= 100; ++i) {
    for (j = 0; j < i; ++j) {
      DP[i][j][1] = DP[i-1][j-1][1] + DP[i-1][j][0];
      DP[i][j][0] = DP[i-1][j][1] + DP[i-1][j][0];
    }
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    printf("%d\n", DP[n][k][1] + DP[n][k][0]);
  }
  return 0;
}