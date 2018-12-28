#include <cstdio>
using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }
int get_min(int a, int b, int c) { return get_min(get_min(a, b), c); }
int get_max(int a, int b) { return a > b ? a : b; }
int get_max(int a, int b, int c) { return get_max(get_max(a, b), c); }

int main(int argc, char *argv[]) {
  int n, map[100000][3], dp[2][3][2];
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<3; ++j) {
      scanf("%d", &map[i][j]);
    }
  }

  dp[0][0][0] = dp[0][0][1] = map[0][0];
  dp[0][1][0] = dp[0][1][1] = map[0][1];
  dp[0][2][0] = dp[0][2][1] = map[0][2];

  for (int i=1; i<n; ++i) {
    dp[1][0][0] = map[i][0] + get_max(dp[0][0][0], dp[0][1][0]);
    dp[1][1][0] = map[i][1] + get_max(dp[0][0][0], dp[0][1][0], dp[0][2][0]);
    dp[1][2][0] = map[i][2] + get_max(dp[0][1][0], dp[0][2][0]);

    dp[1][0][1] = map[i][0] + get_min(dp[0][0][1], dp[0][1][1]);
    dp[1][1][1] = map[i][1] + get_min(dp[0][0][1], dp[0][1][1], dp[0][2][1]);
    dp[1][2][1] = map[i][2] + get_min(dp[0][1][1], dp[0][2][1]);

    for (int j=0; j<3; ++j) {
      for (int k=0; k<2; ++k) {
        dp[0][j][k] = dp[1][j][k];
      }
    }
  }

  printf("%d %d\n", get_max(dp[0][0][0], dp[0][1][0], dp[0][2][0])
                  , get_min(dp[0][0][1], dp[0][1][1], dp[0][2][1]));
  return 0;
}
