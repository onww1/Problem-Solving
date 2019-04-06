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

void open() {
  TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
}

const int SZ = 1 << 20;
const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, M, K;
ll A[SZ], tree[2 * SZ];

ll init(int node, int start, int end);
void update(int node, int start, int end, int idx, ll val);
ll get_val(int node, int start, int end, int left, int right);

int main(int argc, char *argv[]) {
  open();

  N = readInt(), M = readInt(), K = readInt();
  for (int i = 0; i < N; ++i) A[i] = readLL();
  init(1, 0, N - 1);

  M += K;
  int a, b, c;
  while (M--) {
    a = readInt(), b = readInt(), c = readInt();
    if (a == 1) {
      update(1, 0, N - 1, b - 1, (ll)c);
      A[b - 1] = c;
    } else {
      printf("%lld\n", get_val(1, 0, N - 1, b - 1, c - 1));
    }
  }

  return 0;
}

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = A[start] ? A[start] : -1;
  int mid = (start + end) / 2;
  ll left = init(node * 2, start, mid);
  ll right = init(node * 2 + 1, mid + 1, end);
  if (left == -1 || right == -1) return tree[node] = -1;
  return tree[node] = left * right % MOD;
}

void update(int node, int start, int end, int idx, ll val) {
  if (idx < start || end < idx) return;
  if (start == end) {
    tree[node] = val ? val : -1;
    return;
  }

  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, val);
  update(node * 2 + 1, mid + 1, end, idx, val);
  if (tree[node * 2] == -1 || tree[node * 2 + 1] == -1) tree[node] = -1;
  else tree[node] = tree[node * 2] * tree[node * 2 + 1] % MOD;
}

ll get_val(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return 1LL;
  if (left <= start && end <= right) return tree[node] == -1 ? 0 : tree[node];
  int mid = (start + end) / 2;
  return get_val(node * 2, start, mid, left, right) * 
         get_val(node * 2 + 1, mid + 1, end, left, right) % MOD;
}