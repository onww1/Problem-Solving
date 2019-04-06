#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct point { 
  int l, r, c, w;
};

const int MAX = 30;
const int move_r[] = {-1, 1, 0, 0, 0, 0};
const int move_c[] = {0, 0, -1, 1, 0, 0};
const int move_l[] = {0, 0, 0, 0, -1, 1};
int L, R, C;

char map[MAX][MAX][MAX + 1];
bool visited[MAX][MAX][MAX];

bool check(int l, int r, int c) { return l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C; }

int main(int argc, char *argv[]) {
  int i, j, k, ans;
  point dst;

  while (true) {
    scanf("%d %d %d", &L, &R, &C);
    if (!L && !R && !C) break;
    memset(visited, false, sizeof(visited));
    queue <point> q; ans = 0x7f7f7f7f;
    for (i = 0; i < L; ++i) 
      for (j = 0; j < R; ++j) {
        scanf(" %s", map[i][j]);
        for (k = 0; k < C; ++k) {
          if (map[i][j][k] == 'S') {
            visited[i][j][k] = true;
            q.push({i, j, k, 0});
          } else if (map[i][j][k] == 'E') {
            dst = {i, j, k, 0};
            map[i][j][k] = '.';
          }
        }
      }
    
    while (!q.empty()) {
      int l = q.front().l;
      int r = q.front().r;
      int c = q.front().c;
      int w = q.front().w;
      q.pop();

      if (dst.l == l && dst.r == r && dst.c == c) {
        ans = w;
        break;
      }

      for (k = 0; k < 6; ++k) {
        int dl = l + move_l[k];
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (check(dl, dr, dc) && !visited[dl][dr][dc] && map[dl][dr][dc] == '.') {
          visited[dl][dr][dc] = true;
          q.push({dl, dr, dc, w + 1});
        }
      }
    }

    if (ans == 0x7f7f7f7f) printf("Trapped!\n");
    else printf("Escaped in %d minute(s).\n", ans);
  }
  return 0;
}