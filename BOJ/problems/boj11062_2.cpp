#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int T, N, DP[MAX + 1][MAX + 1], S[MAX + 1];

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
      scanf("%d", &DP[i][i]);
      S[i] = S[i - 1] + DP[i][i];
    }

    for (int d = 2; d <= N; ++d) {
      for (int i = 1, j = d; j <= N; ++i, ++j) {
        int l = S[j] - S[i - 1] - DP[i + 1][j];
        int r = S[j] - S[i - 1] - DP[i][j - 1];
        DP[i][j] = max(l, r);
      }
    }

    printf("%d\n", DP[1][N]);
  }
}
