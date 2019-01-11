#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#define MOD 1000000007LL
#define INF 1023456789LL
using namespace std;

struct edge {
  int v, w;
};

vector <edge> edges[100050];
int mx = 0;

int solve(int node, int parent) {
  vector <int> dist;
  for (auto it : edges[node]) {
    if (it.v == parent) continue;
    dist.push_back(it.w + solve(it.v, node));
  }

  if (dist.size() == 0) return 0;
  sort(dist.begin(), dist.end(), greater<int>());
  mx = max(mx, dist[0] + (dist.size() > 1 ? dist[1] : 0));
  return dist[0];
}

int main(int argc, char *argv[]) {
  int n, i, u, v, w;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &u);
    while (1) {
      scanf("%d", &v);
      if (~v) {
        scanf("%d", &w);
        edges[u].push_back({v, w});
      } else break;
    }
  }

  solve(1, 0);
  return !printf("%d\n", mx);
}
