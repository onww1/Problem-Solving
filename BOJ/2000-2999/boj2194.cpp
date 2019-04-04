/*
 *  BOJ 2194. 유닛 이동시키기
 * 
 *  BFS 문제인데 한 개체가 부피가 커서 그 영역을 다 확인해야 하는 문제였죠.
 *  저는 그것을 한 칸의 개체의 움직임으로 바꾸기 위해서 벽 정보를 받을 때,
 *  그것을 기준으로 이 개체가 갈 수 없는 영역을 모두 벽으로 처리를 했습니다.
 *  그렇게 함으로써 그저 한 점의 이동으로 움직임을 체크할 수 있었습니다.
 */

#include <cstdio>
#include <queue>
using namespace std;

// fast io
char buf[1 << 17];
inline char read() {
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

// 위치를 저장할 구조체
struct point {
  int r, c, w;
};

int n, m, a, b, d, k;
int move_r[] = {-1, 1, 0, 0}, move_c[] = {0, 0, -1, 1}; 
bool map[505][505], visited[505][505];

// 범위를 넘어서는지 확인.
bool check(int r, int c) { return r > 0 && r <= n && c > 0 && c <= m; }

int main(int argc, char *argv[]) {
  int i, j, l, ans = 0x7f7f7f7f;
  n = readInt(), m = readInt();
  a = readInt(), b = readInt();
  k = readInt();
  n -= a - 1, m -= b - 1; // 한 칸의 개체의 움직임으로 볼 것이므로 남는 부분 잘라줍니다.

  // 입력을 받으면서 갈 수 없는 부분을 모두 벽으로 처리해줍니다.
  for (i = 0; i < k; ++i) {
    int x = readInt(), y = readInt();
    for (j = x; j > 0 && j > x - a; --j) 
      for (l = y; l > 0 && l > y - b; --l)
        map[j][l] = true;
  }

  // queue에 시작점을 넣고, 도착점을 따로 저장해둡니다.
  queue <point> q;
  q.push({readInt(), readInt(), 0});
  point dst = {readInt(), readInt()};
  visited[q.front().r][q.front().c] = true;

  // 만약 시작점과 도착점이 놓을 수 없는 위치거나 범위를 넘어가면 -1을 출력합니다.
  if (!check(q.front().r, q.front().c) || !check(dst.r, dst.c) || 
      map[q.front().r][q.front().c]    || map[dst.r][dst.c])
    return !printf("-1\n");

  while (!q.empty()) {
    point p = q.front();
    q.pop();

    // 현재 지점이 도착점과 같다면 여태 이동한 값을 ans에 넣고 break!
    if (p.r == dst.r && p.c == dst.c) {
      ans = p.w;
      break;
    }

    for (d = 0; d < 4; ++d) {
      int dr = p.r + move_r[d];
      int dc = p.c + move_c[d];
      // 모든 방향에 대해서 갈 수 있는 곳을 방문해줍니다.
      if (check(dr, dc) && !visited[dr][dc] && !map[dr][dc]) {
        visited[dr][dc] = true;
        q.push({dr, dc, p.w + 1});
      }
    }
  }

  // 최종적으로 ans가 INF이면 -1을 출력하고, 아니라면 그 값을 출력합니다.
  return !printf("%d\n", ans == 0x7f7f7f7f ? -1 : ans);
}
