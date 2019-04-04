#include <cstdio>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std; 
typedef pair<int,int> pii;

const int MAX = 100;
const int move_r[4] = {-1, 0, 1, 0};
const int move_c[4] = {0, -1, 0, 1};
int a[MAX][MAX], n;

bool check(int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; }

bool solve(int diff) {
  for (int mn = a[0][0]; mn >= 0 && mn >= a[0][0] - diff; mn--) {
      int mx = mn + diff;
      queue <pii> q; q.push({0, 0});
      bool visited[MAX][MAX] = {1};
      while (!q.empty()) {
          pii cur = q.front();
          q.pop();
          
          if (cur.X == n - 1 && cur.Y == n - 1) return true;
          
          for (int k = 0; k < 4; k++) {
              int dr = cur.X + move_r[k];
              int dc = cur.Y + move_c[k];
              if (check(dr, dc) && !visited[dr][dc] && mn <= a[dr][dc] && a[dr][dc] <= mx) {
                  visited[dr][dc] = true;
                  q.push({dr, dc});
              }
          }
      }
  }
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j) 
      scanf("%d", &a[i][j]);

  int s = 0, e = 201, m;
  while (s < e) {
    m = (s + e) / 2;
    if (solve(m)) e = m;
    else s = m + 1;
  }

  return !printf("%d\n", solve(s) ? s : s + 1);
}