/*
 *  BOJ 15678. 연세워터파크 
 * 
 *  시간 복잡도 : O(NlogN) 
 *  공간 복잡도 : O(D)
 * 
 *  처음 지점에서 시작해서 하나씩 나가면서 이전 위치에서 얻을 수 있는 최댓값과 현재 값의 비교를 통해 
 *  최댓값을 갱신해 나가는 식의 문제였습니다. 
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <ll, int> pli;

// Fast I/O
const int BUFFER_SIZE = 1 << 17;
char buf[BUFFER_SIZE];
inline char read() {
  static int idx = BUFFER_SIZE;
  if (idx == BUFFER_SIZE) {
    int nidx = fread(buf, 1, BUFFER_SIZE, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}
inline ll readLL() {
  ll sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}

const int MAX = 1e5;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
int N, D;
ll A, mx = -LL_INF;
priority_queue <pli> pq;

int main(int argc, char *argv[]) {
  N = readInt(), D = readInt(), A = readLL();
  pq.push({A, 0});
  mx = max(mx, A);  // 맨 처음 값을 mx로 한다.

  for (int i = 1; i < N; ++i) {
    A = readLL();
    
    // 갈 수 없는 지점들은 모두 지워준다.
    while (!pq.empty() && pq.top().Y < i - D) pq.pop();

    // 갈 수 있는 지점들의 값이 음수면 현재 값을 넣어주고, 양수면 더해서 넣어준다.
    if (pq.top().X < 0) pq.push({A, i});
    else pq.push({A + pq.top().X, i});

    // mx 값을 갱신한다.
    mx = max(mx, pq.top().X);
  }

  return !printf("%lld\n", mx);
}
