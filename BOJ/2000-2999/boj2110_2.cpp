/*
 *  BOJ 2110. 공유기 설치 
 * 
 *  가장 인접한 두 공유기 사이의 최대 거리를 이분탐색으로 결정합니다.
 *  현재 결정해놓은 가장 인접한 두 공유기 사이의 최대 거리를 가지고 모든 공유기를 놓는데 
 *  모두 정해놓은 거리보다 길게 놓도록 합니다. 
 *  그렇게 해서 되면, 최대 거리를 더 늘리고, 안되면 줄입니다.
 */

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2e5;
int n, c, a[MAX];

// 현재 최대 거리로 가능한지 확인하는 함수.
bool solve(int prev, int len, int remain) {
  if (remain == 1) {
    if (a[n-1] - a[prev] >= len) return true;
    return false;
  }

  int idx = prev + 1;
  while (a[idx] - a[prev] < len && idx + remain - 1 < n) ++idx;
  if (a[idx] - a[prev] < len) return false;
  if (solve(idx, len, remain - 1)) return true;
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);

  // 최대 거리를 이분탐색으로 결정
  int s = 0, e = 1e9, m;
  while (s < e) {
    m = (s + e) / 2;
    if (solve(0, m, c - 1)) s = m + 1; // 성공 시, 최대 거리를 늘림.
    else e = m; // 실패 시, 최대 거리를 줄임.
  }
  return !printf("%d\n", solve(0, s, c - 1) ? s : s - 1);
}