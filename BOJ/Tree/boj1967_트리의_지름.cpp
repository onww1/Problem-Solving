#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
  int v, w;
};

vector <edge> edges[10050];
bool visited[10050] = {true};
int mx;

int solve(int node) {
  vector <int> dist;
  for (auto it : edges[node]) {
    if (visited[it.v]) continue;
    visited[it.v] = true;
    dist.push_back(it.w + solve(it.v));
  }

  if (dist.size() == 0) return 0;
  sort(dist.begin(), dist.end());
  mx = max(mx, dist[dist.size() - 1] + dist[dist.size() - 2]);
  return dist[dist.size() - 1];
}

int main(int argc, char *argv[]) {
  int n, u, v, w, i;
  scanf("%d", &n);
  for (i = 0; i < n-1; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    edges[u-1].push_back({v-1, w});
  }
  
  solve(0);
  return !printf("%d\n", mx);
}