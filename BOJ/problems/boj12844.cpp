/*
 *  BOJ 12844. XOR
 * 
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(N) 
 *  
 *  일반적인 다른 세그먼트 트리 문제랑 똑같습니다. 
 *  그냥 그 연산이 XOR이라는 것밖에 다른 점이 없습니다.
 * 
 *  다만 구간이 반드시 a < b로 주어지지 않는점과 
 *  XOR은 같은 수에 대해서 XOR을 할 떄, 홀수번하는 것만 유효하게 XOR해주면 된다는 점이 중요합니다.
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

const int SZ = 1 << 19;
int N, M, A[SZ], tree[2 * SZ], lazy[2 * SZ];

void swap(int &a, int &b);
int init(int node, int start, int end);
void update_lazy(int node, int start, int end);
void update_range(int node, int start, int end, int left, int right, int c);
int get_val(int node, int start, int end, int left, int right);

int main(int argc, char *argv[]) {
  N = readInt();
  for (int i = 0; i < N; ++i) A[i] = readInt();
  init(1, 0, N - 1);

  M = readInt();
  int t, a, b, c;
  while (M--) {
    t = readInt();
    a = readInt();
    b = readInt();
    if (a > b) swap(a, b);

    if (t == 1) {
      c = readInt();
      update_range(1, 0, N - 1, a, b, c);
    } else {
      printf("%d\n", get_val(1, 0, N - 1, a, b));
    }
  }

  return 0;
}

// SWAP!
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// 초기화 함수
int init(int node, int start, int end) {
  if (start == end) return tree[node] = A[start];
  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) ^ init(node * 2 + 1, mid + 1, end);
}

// 레이지 업데이트
void update_lazy(int node, int start, int end) {
  if (!lazy[node]) return;
  if ((end - start + 1) % 2) tree[node] ^= lazy[node];
  if (start != end) {
    lazy[node * 2] ^= lazy[node];
    lazy[node * 2 + 1] ^= lazy[node];
  }
  lazy[node] = 0;
}

// 구간 업데이트
void update_range(int node, int start, int end, int left, int right, int c) {
  update_lazy(node, start, end);

  if (end < left || right < start) return;
  if (left <= start && end <= right) {
    if ((end - start + 1) % 2) tree[node] ^= c;
    if (start != end) {
      lazy[node * 2] ^= c;
      lazy[node * 2 + 1] ^= c;
    }
    return;
  }

  int mid = (start + end) / 2;
  update_range(node * 2, start, mid, left, right, c);
  update_range(node * 2 + 1, mid + 1, end, left, right, c);
  tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

// 구간의 XOR을 구하는 함수
int get_val(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);

  if (end < left || right < start) return 0;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;
  return get_val(node * 2, start, mid, left, right) ^ get_val(node * 2 + 1, mid + 1, end, left, right);
}