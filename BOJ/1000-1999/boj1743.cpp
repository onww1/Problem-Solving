#include <cstdio>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int MAX = 100;
const int move_r[] = {-1, 1, 0, 0};
const int move_c[] = {0, 0, -1, 1};

bool map[MAX][MAX];
bool vst[MAX][MAX];

int main(int argc, char *argv[]) {
  int n, m, k, r, c, i, j, cnt;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < k; ++i) {
    scanf("%d %d", &r, &c);
    map[r-1][c-1] = true;
  }

  int ans = 1;
  vector <pii> stack;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (!vst[i][j] && map[i][j]) {
        cnt = 0;
        stack.push_back({i, j});
        while (!stack.empty()) {
          r = stack.back().X;
          c = stack.back().Y;
          stack.pop_back();

          if (vst[r][c]) continue;
          vst[r][c] = true; ++cnt;

          for (k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr >= 0 && dr < n && dc >= 0 && dc < m && map[dr][dc])
              stack.push_back({dr, dc});
          }
        }
        ans = max(ans, cnt);
      }
    }
  }
  return !printf("%d\n", ans);
}