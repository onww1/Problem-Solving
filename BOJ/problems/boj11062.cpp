#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000;
const int INF = 0x7f7f7f7f;
int T, N, A[MAX + 1], DP[MAX + 1][MAX + 1];

int solve(int s, int e) {
  if (s + 1 >= e) return max(A[s], A[e]);

  int &ret = DP[s][e];
  if (ret != -1) return ret;
  ret = A[s] + min(solve(s + 2, e), solve(s + 1, e - 1));
  ret = max(ret, A[e] + min(solve(s + 1, e - 1), solve(s, e - 2)));
  return ret;
}

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0, N - 1));
  }
  return 0;
}
