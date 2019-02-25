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

const int SZ = 1 << 19;
const int MAX = 5e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, M, od, idx[MAX + 1], cn[MAX + 1], A[SZ], tree[2 * SZ], lazy[2 * SZ];
vector <int> edges[MAX + 1];

int dfs(int);
void update_lazy(int, int, int);
void update_range(int, int, int, int, int, int);
int get_val(int, int, int, int);

int main(int argc, char *argv[]) {
  open();

  N = readInt(), M = readInt(), A[1] = readInt();
  for (int i = 2; i <= N; ++i) {
    A[i] = readInt();
    edges[readInt()].push_back(i);
  }

  dfs(1);

  for (int i = 1; i <= N; ++i) 
    update_range(1, 1, N, idx[i], idx[i], A[i]);

  char c; int a, x;
  for (int i = 0; i < M; ++i) {
    c = read();
    while (c == ' ' || c == '\n') c = read();
    a = readInt();

    if (c == 'p') {
      x = readInt();
      update_range(1, 1, N, idx[a] + 1, idx[a] + cn[a], x);
    } else {
      printf("%d\n", get_val(1, 1, N, idx[a]));
    }
  }

  return 0;
}

int dfs(int node) {
  idx[node] = ++od;

  int cnt = 0;
  for (int next : edges[node]) 
    cnt += dfs(next);
  
  cn[node] = cnt;
  return cnt + 1;
}

void update_lazy(int node, int start, int end) {
  if (lazy[node] == 0) return;
  tree[node] += (end - start + 1) * lazy[node];
  if (start != end) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

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

int get_val(int node, int start, int end, int idx) {
  update_lazy(node, start, end);

  if (idx < start || end < idx) return 0;
  if (start == end) return tree[node];

  int mid = (start + end) / 2;
  return get_val(node * 2, start, mid, idx) + get_val(node * 2 + 1, mid + 1, end, idx);
}