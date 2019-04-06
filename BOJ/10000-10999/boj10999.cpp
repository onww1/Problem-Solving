#define NON_SUBMIT

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;

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

void open() {
  TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
}

const int SZ = 1 << 20;
const int MAX = 1e6;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
 
int N, M, K;
ll A[SZ], tree[2 * SZ], lazy[2 * SZ];

ll init(int node, int start, int end);
void update_lazy(int node, int start, int end);
void update_range(int node, int start, int end, int left, int right, ll diff);
ll sum(int node, int start, int end, int left, int right);

int main(int argc, char *argv[]) {
  open();
  N = readInt(), M = readInt(), K = readInt();
  for (int i = 0; i < N; ++i) A[i] = readLL();
  init(1, 0, N - 1);

  M += K;
  int a, b, c; ll d;
  while (M--) {
    a = readInt(), b = readInt(), c = readInt();
    if (a == 1) {
      d = readLL();
      update_range(1, 0, N - 1, b - 1, c - 1, d);
    } else {
      printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
    }
  }

  return 0;
}

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = A[start];
  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) + 
                      init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
  if (lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_range(int node, int start, int end, int left, int right, ll diff) {
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

ll sum(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);
  if (end < left || right < start) return 0LL;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}