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
#include <deque>
#include <map>
#include <set>
#define X first
#define Y second

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
typedef pair<int, pii> piii;

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

void open() {
  TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
}

const int MAX = 1000;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N;
pii pos[MAX + 1];

int main(int argc, char *argv[]) {
  open();

  N = readInt();
  for (int i = 0; i < N; ++i) pos[i] = { readInt(), readInt() };
  sort(pos, pos + N);
  
  int ans = N;
  for (int i = 0; i < N; ++i) {
    vector <pii> lower, upper;
    for (int j = 0; j < N; ++j) {
      if (pos[j].Y <= pos[i].Y) lower.push_back(pos[j]);
      else upper.push_back(pos[j]);
    }

    int lower_idx = 0, upper_idx = 0;
    while (lower_idx < lower.size() || upper_idx < upper.size()) {
      int x = INF;
      if (lower_idx < lower.size()) x = min(x, lower[lower_idx].X);
      if (upper_idx < upper.size()) x = min(x, upper[upper_idx].X);
      while (lower_idx < lower.size() && lower[lower_idx].X == x) lower_idx++;
      while (upper_idx < upper.size() && upper[upper_idx].X == x) upper_idx++;
      ans = min(ans, max({lower_idx, (int)lower.size() - lower_idx, upper_idx, (int)upper.size() - upper_idx}));
    }
  }

  return !printf("%d\n", ans);
}
