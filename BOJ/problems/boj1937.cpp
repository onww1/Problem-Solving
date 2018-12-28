#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
  int r, c, w;
};

bool cmp(point a, point b) {
  return a.w < b.w;
}

int n;
int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= n) return false;
  return true;
}


int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  vector< vector<int> > map(n, vector<int>(n));
  vector< vector<int> > dp(n, vector<int>(n, 1));
  vector<point> vec(n * n);

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      cin >> map[i][j];
      vec.push_back({i, j, map[i][j]});
    }
  }

  int max = 1;
  sort(vec.begin(), vec.end(), cmp);
  for (int i=0; i<vec.size(); ++i) {
    int r = vec[i].r;
    int c = vec[i].c;
    int w = vec[i].w;

    for (int k=0; k<4; ++k) {
      int dr = r + move_r[k];
      int dc = c + move_c[k];
      if (check(dr, dc) && map[dr][dc] > map[r][c]) {
        if (dp[dr][dc] < dp[r][c] + 1) {
          dp[dr][dc] = dp[r][c] + 1;
          max = dp[dr][dc] > max ? dp[dr][dc] : max;
        }
      }
    }
  }

  cout << max << '\n';

  return 0;
}