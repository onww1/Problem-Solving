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

const int SZ = 1 << 16;
const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, M, Y[SZ], A[SZ], tree[2 * SZ];

int init(int node, int start, int end);
int get_max(int node, int start, int end, int left, int right);

int main(int argc, char *argv[]) {
  open();

  N = readInt();
  for (int i = 0; i < N; ++i) {
    Y[i] = readInt();
    A[i] = readInt();
  }
  init(1, 0, N - 1);

  M = readInt();
  while (M--) {
    int y = readInt(), x = readInt();
    int yidx = lower_bound(Y, Y + N, y) - Y;
    if (yidx == N || Y[yidx] != y) yidx--;
    int xidx = lower_bound(Y, Y + N, x) - Y;
    int mx = get_max(1, 0, N - 1, yidx + 1, xidx - 1);
    
    bool y_valid = !(yidx == -1 || Y[yidx] != y);
    bool x_valid = !(xidx == N || Y[xidx] != x);
    if (y_valid && x_valid && x - y == xidx - yidx && A[yidx] >= A[xidx] && 
        mx < A[xidx])
        puts("true");
    else if ((x_valid && y_valid && A[yidx] < A[xidx]) ||
             (x_valid && mx >= A[xidx]) ||
             (y_valid && mx >= A[yidx]))
        puts("false");
    else
        puts("maybe");
  }
  
  return 0;
}

int init(int node, int start, int end) {
  if (start == end) return tree[node] = A[start];
  int mid = (start + end) / 2;
  return tree[node] = max(init(node * 2, start, mid),
                          init(node * 2 + 1, mid + 1, end));
}

int get_max(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return 0;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return max(get_max(node * 2, start, mid, left, right),
             get_max(node * 2 + 1, mid + 1, end, left, right));
}