#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
enum { E, S, W, N };
enum { L, R };
const int MAX = 100;
const int move_r[] = {0, 1, 0, -1};
const int move_c[] = {1, 0, -1, 0};

int n, m, DP = E, CC = L;
char map[MAX][MAX + 1];
bool visited[MAX][MAX];
pii mm[4][2];

bool check(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= m || map[r][c] == 'X') return false;
  return true;
}

void init() {
  mm[E][0] = {1e9,  -1}, mm[E][1] = {1e9,  -1};
  mm[W][0] = {1e9, 1e9}, mm[W][1] = { -1, 1e9};
  mm[S][0] = { -1, 1e9}, mm[S][1] = { -1,  -1};
  mm[N][0] = {1e9, 1e9}, mm[N][1] = {1e9,  -1};
  memset(visited, false, MAX * n);
}

void get_outer(int r, int c) {
  init();
  queue <pii> q;
  q.push({r, c}); visited[r][c] = true;
  while (!q.empty()) {
    int r = q.front().X, c = q.front().Y;
    q.pop();

    if (mm[E][0].Y < c) mm[E][0] = mm[E][1] = {r, c};
    else if (mm[E][0].Y == c) {
      mm[E][0] = {min(mm[E][0].X, r), c};
      mm[E][1] = {max(mm[E][1].X, r), c};
    }
    if (mm[W][0].Y > c) mm[W][0] = mm[W][1] = {r, c};
    else if (mm[W][0].Y == c) {
      mm[W][0] = {min(mm[W][0].X, r), c};
      mm[W][1] = {max(mm[W][1].X, r), c};
    }
    if (mm[N][0].X > r) mm[N][0] = mm[N][1] = {r, c};
    else if (mm[N][0].X == r) {
      mm[N][0] = {r, min(mm[N][0].Y, c)};
      mm[N][1] = {r, max(mm[N][1].Y, c)};
    }
    if (mm[S][0].X < r) mm[S][0] = mm[S][1] = {r, c};
    else if (mm[S][0].X == r) {
      mm[S][0] = {r, min(mm[S][0].Y, c)};
      mm[S][1] = {r, max(mm[S][1].Y, c)};
    }

    for (int k = 0; k < 4; ++k) {
      int dr = r + move_r[k];
      int dc = c + move_c[k];
      if (check(dr, dc) && map[dr][dc] == map[r][c] && !visited[dr][dc]) {
        visited[dr][dc] = true;
        q.push({dr, dc});
      }
    }
  } 
}
  
bool find(int &r, int &c) {
  int cur_r, cur_c;
  if ((CC == L && (DP == E || DP == N)) || (CC == R && (DP == W || DP == S)))
    cur_r = mm[DP][0].X, cur_c = mm[DP][0].Y;
  else cur_r = mm[DP][1].X, cur_c = mm[DP][1].Y;

  int dr = cur_r + move_r[DP], dc = cur_c + move_c[DP];
  if (check(dr, dc)) { r = dr, c = dc; return true; }
  return false;
}

int main(int argc, char *argv[]) {
  int i, j, r = 0, c = 0;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) scanf(" %s", map[i]);

  vector <char> ans;
  ans.push_back(map[0][0]);

  while (true) {
    get_outer(r, c);
    for (i = 0; i < 4; ++i) {
      if (find(r, c)) break;
      else {
        CC = 1 - CC;
        if (find(r, c)) break;
      }
      DP = (DP + 1) % 4;
    }
    if (i == 4) break;
    else ans.push_back(map[r][c]);
  }

  for (i = 0; i < ans.size(); ++i) printf("%c", ans[i]);
  return !printf("\n");
}