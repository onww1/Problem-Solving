#include <cstdio>
#include <algorithm>
using namespace std;

int DP[1005][31];
int main(int argc, char *argv[]) {
  int t, w, a, i, j, mx = 0;
  scanf("%d %d", &t, &w);
  for (i = 1; i <= t; ++i) {
    scanf("%d", &a);
    for (j = 0; j <= w; ++j) {
      if (j % 2 == a - 1) DP[i][j] = max(DP[i-1][j], j > 0 ? DP[i-1][j-1] : 0) + 1;
      else DP[i][j] = DP[i-1][j];
    }
  }
  
  for (j = 0; j <= w; ++j) mx = max(mx, DP[t][j]);
  return !printf("%d\n", mx);
}