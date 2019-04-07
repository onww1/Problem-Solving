#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

const int MAX = 300;
int N, M, R, ans[MAX][MAX];

pii get_idx(int n, int m, int r, int c, int p) {
  p %= (2 * n + 2 * m - 4);
  
  while (p) {
    if (r == 0 && c > 0) {
      if (p >= c) p -= c, c = 0;
      else c -= p, p = 0;
    } else if (r == n - 1 && c < m - 1) {
      if (p >= m - 1 - c) p -= (m - 1 - c), c = m - 1;
      else c += p, p = 0;
    } else if (c == 0 && r < n - 1) {
      if (p >= n - 1 - r) p -= (n - 1 - r), r = n - 1;
      else r += p, p = 0;
    } else if (c == m - 1 && r > 0) {
      if (p >= r) p -= r, r = 0;
      else r -= p, p = 0;
    }
  }
  return {r, c};
}

int main(int argc, char *argv[]) {
  scanf("%d %d %d", &N, &M, &R);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int diff = min({i, j, N - 1 - i, M - 1 - j});
      pii pos = get_idx(N - 2 * diff, M - 2 * diff, i - diff, j - diff, R);
      scanf("%d", &ans[pos.first + diff][pos.second + diff]);
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) printf("%d ", ans[i][j]);
    puts("");
  }

  return 0;
}