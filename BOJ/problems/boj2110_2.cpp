#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2e5;
int n, c, a[MAX];

bool solve(int prev, int len, int remain) {
  if (remain == 1) {
    if (a[n-1] - a[prev] >= len) return true;
    return false;
  }

  int idx = prev + 1;
  while (a[idx] - a[prev] < len && idx + remain - 1 < n) ++idx;
  if (a[idx] - a[prev] < len) return false;
  if (solve(idx, len, remain - 1)) return true;
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);

  int s = 0, e = 1e9, m;
  while (s < e) {
    m = (s + e) / 2;
    if (solve(0, m, c - 1)) s = m + 1;
    else e = m;
  }
  return !printf("%d\n", solve(0, s, c - 1) ? s : s - 1);
}