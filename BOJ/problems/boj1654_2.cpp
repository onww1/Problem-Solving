/*
 *  BOJ 1654. 랜선 자르기
 * 
 *  랜선의 길이를 이분탐색으로 결정합니다. 
 *  이분탐색하면서 이 길이로 되는지 안되는지 확인하고, 그에 따라 조절하면 됩니다.
 */

#include <cstdio>
typedef unsigned long long ull;
const int MAX = 1e6;
int n, k, a[MAX];

// 특정 길이로 잘랐을 때, 얻어지는 랜선의 갯수로 판별.
bool solve(unsigned len) {
  ull cnt = 0;
  for (int i = 0; i < k; ++i) cnt += (a[i] / len);
  return cnt >= n;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < k; ++i) scanf("%d", a + i);

  // 이분탐색
  unsigned s = 0, e = 1 << 31, m;
  while (s < e) {
    m = (s + e) / 2;
    if (solve(m)) s = m + 1;   // 성공 시, 랜선의 길이를 더 늘려봄.
    else e = m;   // 실패 시, 랜선의 길이를 줄임.
  }
  return !printf("%d\n", solve(s) ? s : s - 1);
}