#include <cstdio>
#include <vector>
using namespace std;

vector <int> edges[100050];
int parent[100050];

void solve(int node, int pa) {
  for (int i : edges[node]) {
    if (i == pa) continue;
    parent[i] = node;
    solve(i, node);
  }
}

int main(int argc, char *argv[]) {
  int n, i, u, v;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  parent[1] = -1;
  solve(1, 0);
  for (i = 2; i <= n; ++i) printf("%d\n", parent[i]);
  return 0;
}