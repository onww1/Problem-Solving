/*
 *  BOJ 2618. 경찰차
 * 
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N^2)
 * 
 *  DP[i][j] : 경찰차 1이 마지막으로 처리한 일이 i번째 일이고,
 *             경찰차 2가 마지막으로 처리한 일이 j번째 일인 상황에서 
 *             나머지 일들을 처리하는데 드는 최소 거리의 합 
 * 
 *  DP 항을 위와 같이 정의해두고 재귀함수를 돌려서 모든 경우를 확인해주고, 
 *  그 중에서 최솟값을 얻어내어 출력하도록 했습니다. 
 * 
 *  임무를 분배하는 것에 대한 출력은 맨 처음 상황에서부터 1에 주는게 다음 것과 같은지 
 *  2에 주는게 다음 것과 같은지를 확인함으로써 임무의 분배 순서를 찾아 나갔습니다.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1000;
const int INF = 0x7f7f7f7f;
int N, W, DP[MAX + 1][MAX + 1];
pii T[MAX + 1], T1, T2;

int dist(pii &pos1, pii &pos2) {
  return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int solve(int t1, int t2) {
  if (t1 == W || t2 == W) return 0;

  int &ret = DP[t1][t2];
  if (ret != -1) return ret;
  ret = INF;

  int next = max(t1, t2) + 1;
  ret = min(ret, dist(T[next], t1 ? T[t1] : T1) + solve(next, t2));
  ret = min(ret, dist(T[next], t2 ? T[t2] : T2) + solve(t1, next));
  return ret;
} 

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &W);
  T1 = {1, 1}, T2 = {N, N};
  for (int i = 1; i <= W; ++i) scanf("%d %d", &T[i].first, &T[i].second);
  memset(DP, -1, sizeof(DP));
  printf("%d\n", solve(0, 0));
  for (int i = 1, t1 = 0, t2 = 0; i <= W; ++i) {
    if (dist(T[i], T1) == (i == W ? DP[t1][t2] : DP[t1][t2] - DP[i][t2])) {
      puts("1");
      T1 = T[i];
      t1 = i;
    }
    else {
      puts("2");
      T2 = T[i];
      t2 = i;
    }
  }
  return 0;
}