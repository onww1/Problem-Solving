#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1023456789
#define MOD 1000000007LL
using namespace std;

vector <int> edges[100050];
int dp[100050][18];

int solve(int node, int parent, int color) {
  int &ret = dp[node][color];
  if (~ret) return ret;
  ret = color;
  for (auto it : edges[node]) {
    if (it == parent) continue;
    int val = INF;
    for (int c = 1; c <= 17; ++c) {
      if (c == color) continue;
      val = min(val, solve(it, node, c));
    }
    ret += val;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n, i, u, v, ans = INF;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(dp, -1, sizeof(dp));
  for (i = 1; i <= 17; ++i) {
    ans = min(ans, solve(1, 0, i));
  }
  return !printf("%d\n", ans);
}