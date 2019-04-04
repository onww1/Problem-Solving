/*
 *  BOJ 2934. LRH 식물
 * 
 *  시간 복잡도 : O(NlogK)  (K = 10만)
 *  공간 복잡도 : O(N) 
 * 
 *  나이브하게 주어진 구간에 대해서 끝점의 값을 구해서 그것을 꽃의 수로 정하고, 
 *  그 꽃의 수를 다시 트리에서 빼준 다음, 그 사이 구간에 대해서 1씩 추가하는 식으로 짰습니다.
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
inline ll readLL() {
  ll sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}

const int SZ = 1 << 17;
const int MAX = 1e5;
int N, L, R, tree[2 * SZ], lazy[2 * SZ];

void update_lazy(int, int, int);
void update_range(int, int, int, int, int, int);
int sum(int, int, int, int, int);

int main(int argc, char *argv[]) {
  N = readInt();
  for (int i = 0; i < N; ++i) {
    L = readInt(), R = readInt();

    // 주어진 구간의 끝점에 대해서 값을 구하고, 그 값들의 합을 출력
    int ls = sum(1, 1, MAX, L, L);
    int rs = sum(1, 1, MAX, R, R);
    printf("%d\n", ls + rs);

    // 똑같은 자리에서 꽃이 피지 않으므로 카운트한 만큼 다시 빼준다.
    update_range(1, 1, MAX, L, L, -ls);
    update_range(1, 1, MAX, R, R, -rs);

    // 주어진 구간의 끝점을 제외한 구간에 1씩 더해준다.
    update_range(1, 1, MAX, L + 1, R - 1, 1);
  }

  return 0;
}

// 레이지 업데이트
void update_lazy(int node, int start, int end) {
  if (lazy[node] == 0) return;
  tree[node] += (end - start + 1) * lazy[node];
  if (start != end) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

// 구간 업데이트
void update_range(int node, int start, int end, int left, int right, int diff) {
  update_lazy(node, start, end);

  if (end < left || right < start) return;
  if (left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if (start != end) {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
    return;
  }

  int mid = (start + end) / 2;
  update_range(node * 2, start, mid, left, right, diff);
  update_range(node * 2 + 1, mid + 1, end, left, right, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 세그먼트 트리 구간 합 구하는 함수
int sum(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);

  if (end < left || right < start) return 0;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}