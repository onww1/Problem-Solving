/*
 *  BOJ 2820. 자동차 공장
 * 
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(N)
 * 
 *  dfs를 통해서 한 직원의 부하들의 인덱스를 모여있게 만들도록 바꾼 다음, 
 *  그 인덱스를 가지고 세그먼트 트리를 만들어서 직원들의 월급을 관리해줬습니다. 
 *  이때, 구간 변화에 대한 문제이므로 레이지 프로파게이션으로 구현했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
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

const int SZ = 1 << 19;
const int MAX = 5e5;
int N, M, od, idx[MAX + 1], cn[MAX + 1], A[SZ], tree[2 * SZ], lazy[2 * SZ];
vector <int> edges[MAX + 1];

int dfs(int);
void update_lazy(int, int, int);
void update_range(int, int, int, int, int, int);
int get_val(int, int, int, int);

int main(int argc, char *argv[]) {
  N = readInt(), M = readInt(), A[1] = readInt();
  for (int i = 2; i <= N; ++i) {
    A[i] = readInt();
    edges[readInt()].push_back(i);
  }

  dfs(1); // dfs를 통해서 인덱스를 새롭게 지정해준다.

  for (int i = 1; i <= N; ++i) 
    update_range(1, 1, N, idx[i], idx[i], A[i]);  // 새롭게 지정된 인덱스에 월급을 업데이틓 해준다.

  char c; int a, x;
  for (int i = 0; i < M; ++i) {
    c = read();
    while (c == ' ' || c == '\n') c = read();
    a = readInt();

    // 쿼리에 따라 월급을 업데이트 해주거나 해당 인덱스의 월급을 가져온다.
    if (c == 'p') {
      x = readInt();
      update_range(1, 1, N, idx[a] + 1, idx[a] + cn[a], x);
    } else {
      printf("%d\n", get_val(1, 1, N, idx[a]));
    }
  }

  return 0;
}

// 인덱스 재지정을 위한 dfs
int dfs(int node) {
  idx[node] = ++od;

  int cnt = 0;
  for (int next : edges[node]) 
    cnt += dfs(next);
  
  cn[node] = cnt;
  return cnt + 1;
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

// 특정 인덱스의 값을 가져옴.
int get_val(int node, int start, int end, int idx) {
  update_lazy(node, start, end);

  if (idx < start || end < idx) return 0;
  if (start == end) return tree[node];

  int mid = (start + end) / 2;
  return get_val(node * 2, start, mid, idx) + get_val(node * 2 + 1, mid + 1, end, idx);
}