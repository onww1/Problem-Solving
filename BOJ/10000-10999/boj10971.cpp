#include <cstdio>
#define INF 987654321
using namespace std;

int cache[10][1 << 10];
int n, w[10][10];

int get_min(int a, int b) { return a < b ? a : b; }

int solve(int visited, int cur) {
  if (visited == (1 << n) - 1) {
    if (w[cur][0] == 0) return INF;
    return w[cur][0];
  }
  int &ret = cache[cur][visited];
  if (ret != 0) return ret;
  ret = INF;
  for (int next = 1; next < n; ++next) {
    if (visited & (1 << next)) continue;
    if (w[cur][next] == 0) continue;
    ret = get_min(ret, solve(visited | (1 << next), next) + w[cur][next]);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) 
    for (int j=0; j<n; ++j) 
      scanf("%d", &w[i][j]);

  printf("%d\n", solve(1, 0));
  return 0;
}
