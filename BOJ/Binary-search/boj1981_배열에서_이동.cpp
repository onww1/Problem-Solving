#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std; 
typedef pair<int,int> pii;

const int MAX = 100;
const int move_r[4] = {-1, 0, 1, 0};
const int move_c[4] = {0, -1, 0, 1};
bool visited[MAX][MAX], exists[201];
int a[MAX][MAX], n;

bool check(int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; }

bool solve(int lb, int ub) {
  queue <pii> q; q.push({0, 0});
  visited[0][0] = true;

  int dr, dc, r, c;
  while (!q.empty()) {
    r = q.front().X;
    c = q.front().Y;
    q.pop();

    for (int k = 0; k < 4; ++k) {
      dr = r + move_r[k];
      dc = c + move_c[k];
      if (check(dr, dc) && !visited[dr][dc] && lb <= a[dr][dc] && a[dr][dc] <= ub) {
        visited[dr][dc] = true;
        q.push({dr, dc});
      } 
    }
  }
  
  return visited[n-1][n-1];
}

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      exists[a[i][j]] = true;
    }

  vector <int> vec;
  int llim = min(a[0][0], a[n-1][n-1]);
  int rlim = max(a[0][0], a[n-1][n-1]);
  for (int i = 0; i <= 200; ++i) {
    if (exists[i]) vec.push_back(i);
    if (i == llim) llim = vec.size() - 1;
    if (i == rlim) rlim = vec.size() - 1;
  }

  int left = 0, right = rlim, ans = 2e9;
  while (left <= llim && right < vec.size()) {
    memset(visited, false, sizeof(visited));
    if (solve(vec[left], vec[right])) {
      ans = min(ans, vec[right] - vec[left]);
      left++;
    } else right++;
  }
  return !printf("%d\n", ans);
}