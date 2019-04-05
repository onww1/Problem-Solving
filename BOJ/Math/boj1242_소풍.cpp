/*
 *  BOJ 1242. 소풍 
 * 
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(1) 
 * 
 *  지워야 할 목표에 대한 상대적인 거리를 추적하면서 찾아내는 방법입니다. 
 *  아이디어를 얻어와서 한 것이라 면목 없습니다 ㅠ.ㅠ
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

// Fast I/O
const int BUFFER_SIZE = 1 << 18;
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

int N, M, K;
int main(int argc, char *argv[]) {
  N = readInt(), M = readInt(), K = readInt();
  for (int i = 0; i < N; ++i) {
    int remain = M % (N - i) ? M % (N - i) : N - i; // 이동해야 할 거리를 최소한으로 줄이기
    if (K == remain || i == N - 1) return !printf("%d\n", i + 1); // 이동해야 할 거리가 목표라면 출력
    else K = K > remain ? K - remain : N - i - remain + K;  // 상황에 맞춰서 목표의 거리를 수정
  }
  return 0;
}
