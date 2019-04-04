#include <cstdio>
#include <vector>
#define X first
#define Y second
#define INF 1023456789
using namespace std;

typedef pair<int, int> pii;
pii node[10050], lvl[10050], num[10050];

pii solve(int n, int l) {
  if (n == -1) return {0, 0};

}

int main(int argc, char *argv[]) {
  int n, i, s, l, r, mx = 0;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d %d %d", &s, &l, &r);
    node[s].X = l;
    node[s].Y = r;
    lvl[i].X = INF;
    lvl[i].Y = -INF;
  }

  lvl[1].X = lvl[1].Y = 0;
  solve(1, 1);
  for (i = 1; i <= 10000; ++i) 
    mx = max(mx, lvl[i].Y - lvl[i].X + 1);
  return !printf("%d\n", mx);
}