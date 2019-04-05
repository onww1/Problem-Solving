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

const int MAX = 100;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, M, MAP[MAX][MAX];
bool visited[MAX][MAX];

bool check(int r, int c) {
  int cnt = 0;
  for (int k = 0; k < 4; ++k) {
    int dr = r + move_r[k];
    int dc = c + move_c[k];
    if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
    if (!MAP[dr][dc] && visited[dr][dc]) cnt++;
  }
  return cnt > 1;
}

int main(int argc, char *argv[]) {
  open();

  queue <pii> q[2], rm;
  N = readInt(), M = readInt();
  for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
    MAP[i][j] = readInt();
    // 입력을 받으면서 가장 자리에 있는 0인 지점을 모두 받는다.
    if (!MAP[i][j] && (i == 0 || i == N - 1 || j == 0 || j == M - 1)) {
      q[0].push({i, j});
      visited[i][j] = true;
    }
  }

  int T = 0;
  while (true) {
    if (q[T % 2].empty()) {
      --T;
      break;
    }

    while (!rm.empty()) {
      MAP[rm.front().X][rm.front().Y] = 0;
      rm.pop();
    }

    while (!q[T % 2].empty()) {
      int r = q[T % 2].front().X;
      int c = q[T % 2].front().Y;
      q[T % 2].pop();

      for (int k = 0; k < 4; ++k) {
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
        if (!visited[dr][dc]) {
          if (MAP[dr][dc] && check(dr, dc)) {
            q[1 - T % 2].push({dr, dc});
            rm.push({dr, dc});
            visited[dr][dc] = true;
          }
          else if (!MAP[dr][dc]) {
            q[T % 2].push({dr, dc});
            visited[dr][dc] = true;
          }
        }
      }
    }

    printf("Time : %d\n", T);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) printf("%d ", MAP[i][j]);
      puts(""); 
    }
    puts("");

    ++T;
  }
  
  printf("%d\n", T);
  return 0;
}