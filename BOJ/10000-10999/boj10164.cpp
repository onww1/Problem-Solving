/*
 *  BOJ 10164. 격자상의 경로
 * 
 *  고등학교 시절 풀었던 확률과 통계 문제가 생각났네요.
 *  격자에서 한 점에서 다른 점으로 최단 경로로 이동하는 경우의 수를 구하려면
 *  가로로 이동하는 사건과 세로로 이동하는 사건을 잘 배열하면 되는거죠.
 *  그래서 조합을 이용하여 풀었습니다.
 *  
 *  다만, 이 문제는 모서리 기준이 아니고, 칸 기준이기 때문에 조심해야 합니다.
 *  
 *  i) k = 0일 때, 정답은 n+m-2 C n-1입니다.
 *  ii) k = 1일 때, 표시가 된 지점의 좌표를 (r, c)라고 하면,
 *    정답은 r+c C r * n+m-r-c-2 C n-r-1 입니다.
 * 
 *  여기서 n C r = n C n-r이라는 것을 이용하여 메모리를 아꼈습니다.
 */

#include <cstdio>
#include <algorithm>
using namespace std;

int combination[29][15];
int main(int argc, char *argv[]) {
  int n, m, k, r, c, i, j;
  scanf("%d %d %d", &n, &m, &k);

  // combination을 계산
  for (i = 0; i < 15; ++i) combination[i][i] = 1;
  for (i = 0; i < 29; ++i) combination[i][0] = 1;
  for (i = 2; i < 29; ++i) {
    for (j = 1; j < 15 && j < i; ++j) {
      combination[i][j] = combination[i-1][j] + combination[i-1][j-1];
    }
  }
  
  if (k) { // 표시된 점이 있으면,
    r = (k - 1) / m; // 행을 계산
    c = (k - 1) % m; // 열을 계산
    // 두 조합을 곱한 값을 출력
    return !printf("%d\n", combination[r + c][min(r, c)] 
                         * combination[n + m - r - c - 2][min(n - r - 1, m - c - 1)]);
  } 
  // 표시된 점이 없으면, 해당하는 조합값을 출력
  return !printf("%d\n", combination[n + m - 2][min(n - 1, m - 1)]);
}