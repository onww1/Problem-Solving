// #include <cstdio>
// #include <cstring>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector <int> edges[10050];
// bool visited[10050];
// int a[10050], dp[10050][2];

// int solve(int node, int great) {
//   int &ret = dp[node][great];
//   if (ret != -1) return ret;
//   ret = 0;
//   for (auto it : edges[node]) {
//     if (visited[it]) continue;
//     visited[it] = true;

//     if (great) {
//       ret += solve(it, 0);
//     } else {
//       ret += max(solve(it, 0), a[it] + solve(it, 1));
//     }
//     visited[it] = false;
//   }
//   return ret;
// }

// int main(int argc, char *argv[]) {
//   int n, i, u, v;
//   scanf("%d", &n);
//   for (i = 0; i < n; ++i) scanf("%d", a + i);
//   for (i = 1; i < n; ++i) {
//     scanf("%d %d", &u, &v);
//     edges[--u].push_back(--v);
//     edges[v].push_back(u);
//   }

//   memset(dp, -1, sizeof(dp));
//   visited[0] = true;
//   return !printf("%d\n", max(solve(0, 0), solve(0, 1) + a[0]));
// }

/*
 *  I quoted koosaga's source code.
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> edges[10050];
int a[10050], dp[10050][2];

int solve(int node, int parent, int include) {
  int &ret = dp[node][include];
  if (ret != -1) return ret;
  ret = include ? a[node] : 0;
  for (auto it : edges[node]) {
    if (it == parent) continue;
    int val = solve(it, node, 0);
    if (!include) val = max(val, solve(it, node, 1));
    ret += val;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n, i, u, v;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  memset(dp, -1, sizeof(dp));
  return !printf("%d\n", max(solve(1, 0, 0), solve(1, 0, 1)));
}