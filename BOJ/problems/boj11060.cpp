/*
 *  BOJ 11060. 점프 점프
 * 
 *  DP[i] : i번째로 도착하는 최소 점프 횟수
 *  DP[i] = min {j = 0 ~ i-1} (dp[j] + (a[j] - (i - j) > 0 ? 1 : INF) )
 * 
 *  DP의 항과 점화식을 위와 같이 정의했습니다.
 *  점화식은 i보다 작은 항들에 대해서 만약 그 부분에서 점프해서 올 수 있으면 그 부분의 항에 1을 더한 값과
 *  현재 항을 비교하고 더 작은 값을 취하는 것입니다.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int a[1050], dp[1050];
int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  memset(dp, 0x7f, sizeof(dp)); dp[0] = 0;
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  for (i = 0; i < n; ++i) {
    for (j = 1; j <= a[i]; ++j) {
      // 도달 가능한 거리에 대해서 더 작은 값을 취한다.
      if (i + j < n) dp[i + j] = min(dp[i + j], dp[i] + 1);
      else break;
    }
  }
  // 만약 끝 값이 무한대면 도달하지 못하는 것이므로 -1을 출력하고, 아니라면 해당 값을 출력한다.
  return !printf("%d\n", dp[n-1] == INF ? -1 : dp[n-1]);
}