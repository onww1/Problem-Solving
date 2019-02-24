/*
 *  BOJ 6549. 히스토그램에서 가장 큰 직사각형 
 * 
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(N)
 * 
 *  세그먼트 트리를 이용하여 구간의 최솟값과 그 최솟값의 인덱스를 저장하고, 
 *  전체 구간에서 시작하여 그 구간에서의 최솟값을 뽑아 직사각형의 넓이를 구하고, 
 *  그 최솟값의 인덱스의 왼쪽 구간과 오른쪽 구간에 대하여 재귀적으로 직사각형의 최대 넓이를 구하고,
 *  그 중에서 큰 값을 리턴하는 식으로 구현하였습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

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

const int SZ = 1 << 17;
int N, H[SZ];
pii tree[2 * SZ];

pii init(int node, int start, int end);
pii get_min(int node, int start, int end, int left, int right);
ll solve(int start, int end);

int main(int argc, char *argv[]) {
  for (N = readInt(); N; N = readInt()) {
    for (int i = 0; i < N; ++i) H[i] = readInt();
    init(1, 0, N - 1);
    printf("%lld\n", solve(0, N - 1));
  }

  return 0;
}

// 세그먼트 트리 초기화 함수
pii init(int node, int start, int end) {
  if (start == end) return tree[node] = { H[start], start };
  int mid = (start + end) / 2;
  return tree[node] = min(init(node * 2, start, mid), 
                          init(node * 2 + 1, mid + 1, end));
}

// 구간의 최솟값의 값과 인덱스를 리턴해주는 함수
pii get_min(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return { INF, INF };
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return min(get_min(node * 2, start, mid, left, right),
             get_min(node * 2 + 1, mid + 1, end, left, right));
}

// [s, e] 구간에 대해서 직사각형의 최대 넓이를 리턴
ll solve(int start, int end) {
  if (start > end) return 0;
  else if (start == end) return H[start];

  // 현재 구간에 대한 최솟값을 받음.
  pii mn = get_min(1, 0, N - 1, start, end);

  // 현재 구간에 대한 직사각형의 넓이를 구함
  ll area = 1LL * mn.first * (end - start + 1);

  // 최솟값 왼쪽 범위에 대한 넓이를 구함.
  area = max(area, solve(start, mn.second - 1));

  // 최솟값 오른쪽 범위에 대한 넓이를 구함.
  area = max(area, solve(mn.second + 1, end));
  return area;
}