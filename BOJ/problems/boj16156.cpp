#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<pli,int> plii;

const ll INF = 0x7f7f7f7f7f7f7f7f;
const int MAX = 500;
const int move_r[] = {1, 0, -1, 0};
const int move_c[] = {0, 1, 0, -1};
int n, m, map[MAX][MAX], cnt[MAX];
pli dist[MAX * MAX];

bool check(int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; }

int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &map[i][j]);
  
  if (m == 1) {
    for (int i = 0; i < n; ++i) puts("1");
    return 0;
  }

  memset(dist, 0x7f, sizeof(dist));
  priority_queue < plii, vector<plii>, greater<plii> > pq; 
  for (int i = 0; i < n; ++i) {
    dist[i * m + m - 1] = {0LL, i};
    pq.push({dist[i * m + m - 1], i * m + m - 1});
  }

  while (!pq.empty()) {
    plii cur = pq.top();
    pq.pop();
    if (dist[cur.Y].X < cur.X.X) continue;

    int r = cur.Y / m, c = cur.Y % m;
    if (c == 0) { cnt[cur.X.Y]++; continue; }

    for (int k = 0; k < 4; ++k) {
      int dr = r + move_r[k];
      int dc = c + move_c[k];
      if (check(dr, dc) && dist[dr * m + dc].X > dist[cur.Y].X + map[dr][dc]) {
        dist[dr * m + dc] = {dist[cur.Y].X + map[dr][dc], dist[cur.Y].Y};
        pq.push({dist[dr * m + dc], dr * m + dc});
      }  
    }
  }

  for (int i = 0; i < n; ++i) printf("%d\n", cnt[i]);
  return 0;
}
