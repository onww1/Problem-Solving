#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
  
const int MAX = 100;
const int INF = 0x7f7f7f7f;
int N, M, A[MAX + 1], C[MAX + 1], DP[MAX + 1][MAX * MAX + 1];

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; ++i) scanf("%d", A + i);
  for (int i = 0; i < N; ++i) scanf("%d", C + i);
  
  DP[0][C[0]] = A[0];
  for (int i = 1; i < N; ++i) {
    DP[i][C[i]] = A[i];
    for (int j = 1; j <= MAX * MAX; ++j) {
      if (DP[i - 1][j]) DP[i][j + C[i]] = max(DP[i][j + C[i]], DP[i - 1][j] + A[i]);
      DP[i][j] = max(DP[i][j], DP[i - 1][j]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= MAX * MAX; ++i) {
    if (DP[N - 1][i] >= M) {
      ans = i;
      break;
    }
  }

  return !printf("%d\n", ans);
}