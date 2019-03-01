#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define row first
#define col second
using namespace std;
typedef pair<int,int> pii;

const int MAX = 500;
const int move_r[] = {1, 0, -1, 0};
const int move_c[] = {0, 1, 0, -1};

int N, M, map[MAX][MAX], cnt, mx;
bool visited[MAX][MAX];

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf("%d", &map[i][j]);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (!visited[i][j] && map[i][j]) {
        queue <pii> q;
        q.push({i, j});
        visited[i][j] = true;
        ++cnt;

        int area = 0;
        while (!q.empty()) {
          int r = q.front().row;
          int c = q.front().col;
          q.pop();

          ++area;
          for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
            if (!visited[dr][dc] && map[dr][dc]) {
              q.push({dr, dc});
              visited[dr][dc] = true;
            }
          }
        }

        mx = max(mx, area);
      }
    }
  }

  return !printf("%d\n%d\n", cnt, mx);
}