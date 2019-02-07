/*
 *  BOJ 2805. 나무 자르기
 *  
 *  적절한 절단기의 높이를 이분탐색으로 찾아나갑니다.
 *  저는 이분탐색을 할 때 [s, e)와 같은 범위를 주고 하는 것을 좋아해서,
 *  가장 작은 가능한 값 0과, 될 수 없는 값 1e9 + 1을 각각 s와 e로 설정하고,
 *  이분탐색으로 탐색했습니다. 
 *  s와 e의 중간값인 mid를 절단기의 높이로 하고, 잘리는 나무의 길이를 모두 구했을 때,
 *  원하는 값 m보다 크면 되는 것이므로 이것보다 조금 더 높여서 시도해야 합니다.
 *  그래서 s = mid + 1로 하는 것입니다. 만약 현재 높이에서 불가능하다면 절단기의 높이를 
 *  낮춰야 하므로 e = mid로 합니다.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

// 배열 사이즈
const int MAX = 1e6;
int n, m, h[MAX];

// Fast I/O
char buf[1 << 17];
inline char read() {
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

// 잘리는 나무의 길이를 얻어내는 함수
bool solve(int height) {
  ll sum = 0LL;
  for (int i = 0; i < n; ++i) 
    if (h[i] > height) sum += (h[i] - height);
  return sum >= m;
}

int main(int argc, char *argv[]) {
  n = readInt(), m = readInt();
  for (int i = 0; i < n; ++i) h[i] = readInt();
  
  // 이분탐색
  int s = 0, e = 1e9 + 1, mid;
  while (s < e) {
    mid = (s + e) >> 1;
    if (solve(m)) s = mid + 1; // 성공 시, 더 높은 높이로 시도
    else e = mid; // 실패 시, 더 낮은 높이로 시도
  }
  return !printf("%d\n", solve(s) ? s : s - 1);
}