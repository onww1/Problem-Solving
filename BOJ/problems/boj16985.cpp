#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, pii> piiii;

const int INF = 0x7f7f7f7f;
const int move_r[] = {1, 0, -1, 0, 0, 0};
const int move_c[] = {0, 1, 0, -1, 0, 0};
const int move_f[] = {0, 0, 0, 0, 1, -1};
int MAP[5][5][5], ans = INF, A[5] = {0, 1, 2, 3, 4};
bool visited[5][5][5];

bool _rotate(int floor);
int BFS();
void DFS(int T);

int main(int argc, char *argv[]) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        scanf("%d", &MAP[i][j][k]);
      }
    }
  }

  do { DFS(1); } while (next_permutation(A, A + 5));
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}

bool _rotate(int floor) {
  int tmp[5][5];
  for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) 
    tmp[-(j - 2) + 2][i] = MAP[floor][i][j];

  bool diff = false;
  for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) {
    if (MAP[floor][i][j] != tmp[i][j]) diff = true;
    MAP[floor][i][j] = tmp[i][j];
  }

  return diff;
}

int BFS(pii src, pii dst) {
  memset(visited, false, sizeof(visited));
  queue <piiii> q;
  q.push({{0, 0}, src});
  visited[A[0]][src.X][src.Y] = true;

  while (!q.empty()) {
    int r = q.front().Y.X;
    int c = q.front().Y.Y;
    int f = q.front().X.Y;
    int w = q.front().X.X;
    q.pop();

    if (f == 4 && r == dst.X && c == dst.Y) return w;

    for (int k = 0; k < 6; ++k) {
      int dr = r + move_r[k];
      int dc = c + move_c[k];
      int df = f + move_f[k];
      if (dr < 0 || dr >= 5 || dc < 0 || dc >= 5 || df < 0 || df >= 5) continue;
      if (!visited[A[df]][dr][dc] && MAP[A[df]][dr][dc]) {
        q.push({ {w + 1, df}, {dr, dc} });
        visited[A[df]][dr][dc] = true;
      }
    }
  }

  return INF;
}

void DFS(int T) {
  if (T == 5) {
    if (MAP[A[0]][0][0] && MAP[A[4]][4][4]) ans = min(ans, BFS({0, 0}, {4, 4}));
    if (MAP[A[0]][0][4] && MAP[A[4]][4][0]) ans = min(ans, BFS({0, 4}, {4, 0}));
    if (MAP[A[0]][4][0] && MAP[A[4]][0][4]) ans = min(ans, BFS({4, 0}, {0, 4}));
    if (MAP[A[0]][4][4] && MAP[A[4]][0][0]) ans = min(ans, BFS({4, 4}, {0, 0}));
    return;
  }

  bool flag = true;
  for (int i = 0; i < 4; ++i) {
    if (flag) DFS(T + 1);
    flag = _rotate(A[T]);
  }
}