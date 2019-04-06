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

const int MAX = 1024;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
 
int N, M, A[MAX + 1][MAX + 1], tree[MAX + 1][MAX + 1];

void update(int x, int y, int diff);
int sum(int x, int y);

int main(int argc, char *argv[]) {
  open();

  N = readInt(), M = readInt();
  for (int i = 1; i <= N; ++i) 
    for (int j = 1; j <= N; ++j) {
      A[i][j] = readInt();
      update(i, j, A[i][j]);
    }
  
  int w, x, y, xx, yy;
  while (M--) {
    w = readInt();
    if (w) {
      x  = readInt(), y  = readInt();
      xx = readInt(), yy = readInt();
      printf("%d\n", sum(xx, yy) - sum(xx, y - 1) - sum(x - 1, yy) + sum(x - 1, y - 1));
    } else {
      x = readInt(), y = readInt(), xx = readInt();
      update(x, y, xx - A[x][y]);
      A[x][y] = xx;
    }
  }

  return 0;
}

void update(int x, int y, int diff) {
  while (x <= N) {
    int yy = y;
    while (yy <= N) {
      tree[x][yy] += diff;
      yy += yy & -yy;
    }
    x += x & -x;
  }
}

int sum(int x, int y) {
  int ret = 0;
  while (x > 0) {
    int yy = y;
    while (yy > 0) {
      ret += tree[x][yy];
      yy -= yy & -yy;
    }
    x -= x & -x;
  }
  return ret;
}