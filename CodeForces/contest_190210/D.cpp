#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int MAX = 5e3;
const int INF = 0x7f7f7f7f;

int color[MAX + 1], n, DP[MAX + 1][MAX + 1];

int solve(int s, int e) {
  if (s >= e) return 0;
  int &ret = DP[s][e];
  if (ret != -1) return ret;
  if (color[s] == color[e]) ret = solve(s+1, e-1) + 1;
  else ret = max(solve(s+1, e), solve(s, e-1));
  return ret; 
}

int main(int argc, char *argv[]) {
  int i, j, cnt;
  scanf("%d", &n);
  for (i = 0, cnt = 0; i < n; ++i) {
      scanf("%d", color + cnt);
      if (!cnt || (color[cnt-1] != color[cnt])) ++cnt;
  }
  memset(DP, -1, sizeof(DP));
  return !printf("%d\n", cnt - 1 - solve(0, cnt - 1));
}
