#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> edges[10050];
bool visited[10050];
int a[10050], dp[10050][2];

int solve(int node, int great) {
  int &ret = dp[node][great];
  if (ret != -1) return ret;
  ret = 0;

  for (auto it : edges[node]) {
    
  }

  return ret;
}

int main(int argc, char *argv[]) {
  int n, i, u, v;
  scanf("%d", &n);
  for (i=0; i<n; ++i) scanf("%d", &a[i]);
  for (i=1; i<n; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(dp, -1, sizeof(int) * (n+1) * 2);
  return !printf("%d\n", max(solve(1, 0), solve(1, 1) + a[1]));
}
