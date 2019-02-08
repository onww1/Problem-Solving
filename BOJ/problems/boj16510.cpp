/*
 *  BOJ 16510. Predictable Queue
 * 
 *  시간 복잡도 : O(mlogn)
 *  공간 복잡도 : O(n)
 * 
 *  처음 일부터 시작해서 걸리는 시간을 부분합으로 전처리를 해두고, 
 *  주어지는 값에 대해서 이분탐색을 통해 위치를 찾아서 일의 갯수를 출력했습니다.
 */

#include <cstdio>
using namespace std;
typedef long long ll;

// Fast IO
const int BS = 1 << 17;
char buf[BS];
inline char read() {
  static int idx = BS;
  if (idx == BS) {
    int nidx = fread(buf, 1, BS, stdin);
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
inline ll readLL() {
  ll sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

const int MAX = 2e5;
ll a[MAX + 5];
int main(int argc, char *argv[]) {
  int n = readInt(), m = readInt(), i, t;
  // 부분합 계산
  for (i = 1; i <= n; ++i) a[i] = readInt(), a[i] += a[i-1];

  // 각각의 t에 대해서 이분탐색으로 일의 수를 결정.
  for (i = 0; i < m; ++i) {
    t = readInt();
    int s = 1, e = n + 1, mid;
    while (s < e) {
      mid = (s + e) / 2;
      if (a[mid] > t) e = mid;
      else s = mid + 1;
    }
    printf("%d\n", a[s] > t || s > n ? s-1 : s);
  }
  return 0;
}