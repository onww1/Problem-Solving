/*
 *  BOJ 1168. 조세퍼스 문제 2
 * 
 *  시간 복잡도 : O(N * (log N)^2)
 *  공간 복잡도 : O(N)
 * 
 *  펜윅트리로 모든 수의 자리에 1을 먼저 업데이트를 해둔 다음, 
 *  이동해야 하는 값의 크기를 구하고, 이분탐색을 통해서 그 수의 위치를 찾아 이동했습니다.
 *  그렇게 하나씩 찾아가면서 찾은 수는 0으로 바꿔주는 식으로 하여 모든 순열을 구했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

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

const int MAX = 1e5;
int N, M, tree[MAX + 1], res[MAX + 1];

void update(int, int);
int sum(int);

int main(int argc, char *argv[]) {
  N = readInt(), M = readInt();
  for (int i = 1; i <= N; ++i) update(i, 1);  // 먼저 모든 자리에 1을 업데이트 합니다.

  for (int i = 0, s = 0; i < N; ++i) {
    int remain = M % (N - i);   // M을 남은 수의 갯수로 나눈 나머지를 구해놓고, 그 만큼만 이동하도록 합니다.
    int base = sum(s), right = sum(N);
    int l, r, m, ans;

    if (!remain) remain = N - i;  // 만약 나머지가 0이라면 남은 수의 갯수로 바꿔주어 일관적인 처리를 돕습니다.
    if (right - base >= remain) { // 현재 위치해 있는 수의 오른쪽에 다음 수가 있는 경우
      l = s + 1, r = N, m = 0, ans = N;
      while (l <= r) {
        m = (l + r) / 2;
        if (sum(m) - base >= remain) {
          ans = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    } else {  // 현재 위치해 있는 수의 왼쪽에 다음 수가 있는 경우
      remain -= (right - base);
      l = 1, r = s - 1, m = 0, ans = 1;
      while (l <= r) {
        m = (l + r) / 2;
        if (sum(m) >= remain) {
          ans = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }

    res[i] = ans; // 결과를 저장
    update(ans, -1); // 방문한 수를 0으로 만들어줌.
    s = ans;  // 위치를 현재 위치로 바꿈.
  }

  // 결과 출력
  printf("<%d", res[0]);
  for (int i = 1; i < N; ++i) printf(", %d", res[i]);
  puts(">");

  return 0;
}

// 펜윅트리 업데이트 함수
void update(int node, int diff) {
  while (node <= N) {
    tree[node] += diff;
    node += node & -node;
  }
}

// 펜윅트리 1 ~ node의 합을 구하는 함수
int sum(int node) {
  int ret = 0;
  while (node > 0) {
    ret += tree[node];
    node -= node & -node;
  }
  return ret;
}