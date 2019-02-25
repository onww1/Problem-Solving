/*
 *  BOJ 1655. 가운데를 말해요
 * 
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(K)  (K == 2^15)
 * 
 *  [-10000, 10000] 범위의 수를 [0, 20000] 범위로 보정을 하고, 
 *  해당 수에 해당하는 칸에 1을 업데이트하는 식으로 세그먼트 트리를 만들었고, 
 *  각 노드에는 자신의 구간에 몇 개의 수가 있는지가 저장되어 있으므로 
 *  그 수를 기반으로 중간에 해당하는 수를 찾아 나갔습니다.
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

const int SZ = 1 << 15;
const int MAX = 2e4;
int N, A, M, tree[2 * SZ];

void update(int, int, int, int, int);
int solve(int, int, int, int);

int main(int argc, char *argv[]) {
  N = readInt();
  for (int i = 1; i <= N; ++i) {
    A = readInt() + 10000;  // 수의 범위가 [-10000, 10000]이므로 [0, 20000]으로 보정
    update(1, 0, MAX, A, 1);  // 각 수를 해당 수에 해당하는 자리에 업데이트
    M = (i + 1) / 2;
    printf("%d\n", solve(1, 0, MAX, M) - 10000);
  }
  return 0;
}

// 업데이트 함수
void update(int node, int start, int end, int idx, int diff) {
  if (end < idx || idx < start) return;
  if (start == end) {
    tree[node] += diff;
    return;
  }

  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 세그먼트 트리의 노드 값에 따라서 중간 수를 찾아주는 함수
int solve(int node, int start, int end, int k) {
  if (start == end) return start;
  if (tree[node * 2] < k) 
    return solve(node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
  return solve(node * 2, start, (start + end) / 2, k);
}