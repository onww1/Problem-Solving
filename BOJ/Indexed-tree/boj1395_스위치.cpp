/*
 *  BOJ 1395. 스위치
 * 
 *  시간 복잡도 : O(MlogN) 
 *  공간 복잡도 : O(N)
 * 
 *  XOR 문제와 비슷하게 접근하면 됩니다.
 *  특정 구간에 대해서 같은 구간의 스위치를 두 번 누르면 원상태이므로 그것에 착안하여 
 *  스위치를 누르는 횟수를 카운트한 다음 그것의 수가 홀수이면 상태를 완전히 반전시키는 것입니다. 
 *  그리고 그 반전이라는 것은 구간의 길이에서 현재 켜져있는 것을 뺀 것과 같습니다. 
 *  즉, 세그먼트 트리에는 구간에서 켜져있는 스위치의 수를 가지고 있는데 그것을 구간의 길이에다가 빼주면 
 *  반전이 되는 것과 같으므로 그러한 방식으로 세그를 관리했습니다.
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

const int SZ = 1 << 17;
int N, M, tree[2 * SZ], lazy[2 * SZ];

void update_lazy(int, int, int);
void update_range(int, int, int, int, int);
int sum(int, int, int, int, int);

int main(int argc, char *argv[]) {
  N = readInt(), M = readInt();
  int o, s, t;
  while (M--) {
    o = readInt();
    s = readInt();
    t = readInt();
    if (o) {
      printf("%d\n", sum(1, 1, N, s, t));
    } else {
      update_range(1, 1, N, s, t);
    }
  }

  return 0;
}

// 레이지 업데이트
void update_lazy(int node, int start, int end) {
  if (lazy[node] == 0) return;
  if (lazy[node] % 2) tree[node] = (end - start + 1) - tree[node];
  if (start != end) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

// 구간 업데이트
void update_range(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);

  if (end < left || right < start) return;
  if (left <= start && end <= right) {
    tree[node] = (end - start + 1) - tree[node];
    if (start != end) {
      lazy[node * 2] += 1;
      lazy[node * 2 + 1] += 1;
    }
    return;
  }

  int mid = (start + end) / 2;
  update_range(node * 2, start, mid, left, right);
  update_range(node * 2 + 1, mid + 1, end, left, right);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 구간 합
int sum(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);

  if (end < left || right < start) return 0 ;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}