/*
 *  BOJ 11062. 카드 게임
 * 
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N^2)
 * 
 *  DP[i][j] : i ~ j 번째 카드가 남아있을 때, 얻을 수 있는 최대 수 
 * 
 *  DP 항을 위와 같이 정의해두고, 재귀로 모두 확인하여 값을 구했습니다.
 *  이때, 두 플레이어가 서로 최선을 다하기 때문에 바로 다음 영역에 대한 확인을 할 떄, 
 *  그 중에서 작은 값을 취해야 합니다. 상대편이 최선을 다하기 때문에 분명히 더 큰값이 되도록
 *  가져가기 때문에 작은 값을 취하도록 했습니다.
 */

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
