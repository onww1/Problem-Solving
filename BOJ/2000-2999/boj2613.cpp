/*
 *  BOJ 2613. 숫자구슬
 * 
 *  그룹의 합의 최댓값의 최솟값을 이분탐색으로 결정합니다.
 *  그 값이 되는지 확인할 때는, 최대한 그룹을 정해놓은 수보다 합이 크지 않게 하면서,
 *  많이 합쳐놓습니다. 최대한 한 그룹에 몰아놓을수록 이득입니다. 
 *  그렇게 이분탐색으로 확인하면 끝입니다. 
 */

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 300;
int n, m, a[MAX + 1], psum[MAX + 1], tmp[MAX], res[MAX];

// 정해놓은 값에 대해서 가능한지 확인하는 함수.
bool solve(int prev, int remain, int upper_bound) {

  // 하나만 남았을 때, 이 구슬들의 합이 정해놓은 수보다 작으면 일단 임시 답으로 결정.
  if (remain == 1) {
    if (psum[n] - psum[prev] <= upper_bound) {
      tmp[m-1] = n - prev;
      for (int i = 0; i < m; ++i) res[i] = tmp[i];
      return true;
    } else return false;
  }

  int idx = prev + 1;
  while (idx + remain - 1 < n && psum[idx] - psum[prev] <= upper_bound) ++idx;
  if (psum[idx] - psum[prev] > upper_bound) --idx;
  tmp[m - remain] = idx - prev;
  if (solve(idx, remain - 1, upper_bound)) return true;
  return false;
}

int main(int argc, char *argv[]) {
  int s = 0, e = 0, mid;
  scanf("%d %d", &n, &m);

  // 입력을 받으면서 부분합도 계산해둔다.
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    s = max(s, a[i]);
    psum[i] = psum[i-1] + a[i];
  }
  
  // 이분 탐색을 한다. 시작은 값중 최소, 끝은 모든 수의 합에서 1만큼 큰 것이다.
  e = psum[n] + 1;
  while (s < e) {
    mid = (s + e) >> 1;
    if (solve(0, m, mid)) e = mid; // 성공 시, 최솟값을 줄여본다.
    else s = mid + 1; // 실패 시, 최솟값을 늘린다.
  }
  printf("%d\n", solve(0, m, s) ? s : s + 1);
  for (int i = 0; i < m; ++i) printf("%d ", res[i]);
  return !printf("\n");
}