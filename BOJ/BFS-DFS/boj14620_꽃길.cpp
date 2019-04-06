#include <cstdio>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int MAX = 10;
const int move_r[] = {-1, 1, 0, 0};
const int move_c[] = {0, 0, -1, 1};

int map[MAX][MAX], s[MAX][MAX], n;
bool visited[MAX][MAX];

bool check(int r, int c) {
  if (r == 0 || c == 0 || r == n-1 || c == n-1) return false;
  for (int k = 0; k < 4; ++k) 
    if (visited[r + move_r[k]][c + move_c[k]]) return false;
  return true;
}

void fill(int r, int c, bool v) {
  visited[r][c] = v;
  for (int k = 0; k < 4; ++k)
    visited[r + move_r[k]][c + move_c[k]] = v;
}

int sum(int r, int c) {
  int ret = map[r][c];
  for (int k = 0; k < 4; ++k)
    ret += map[r + move_r[k]][c + move_c[k]];
  return ret;
}

void solve(vector <pii> &pos, int &mn) {
  if (pos.size() == 3) {
    int ss = 0;
    for (auto it : pos) ss += s[it.X][it.Y];
    mn = min(mn, ss);
    return;
  }

  int r = 1, c = 1, i, j;
  if (!pos.empty()) r = pos.back().X, c = pos.back().Y;
  for (i = r; i < n - 1; ++i) {
    for (j = (i == r ? c : 1); j < n - 1; ++j) {
      if (check(i, j)) {
        fill(i, j, true);
        pos.push_back({i, j});
        solve(pos, mn);
        pos.pop_back();
        fill(i, j, false);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int i, j, mn = 1e9;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) 
    scanf("%d", &map[i][j]);
  for (i = 1; i < n - 1; ++i) for (j = 1; j < n - 1; ++j)
    s[i][j] = sum(i, j);

  vector <pii> pos;
  solve(pos, mn);
  return !printf("%d\n", mn);
}