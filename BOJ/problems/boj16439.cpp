#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

char buf[1 << 11];
inline char read() {
  static int idx = 1 << 11;
  if (idx == 1 << 11) {
    int nidx = fread(buf, 1, 1 << 11, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0, minus = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') minus = 1, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

int a[32][32], n, m, mx;
void solve(int T, vector <int> &visited) {
  if (T == 3) {
    int s = 0, mxx = 0;
    for (int i = 0; i < n; ++i) {
      mxx = 0;
      for (int it : visited) mxx = max(mxx, a[i][it]);
      s += mxx;
    }
    mx = max(mx, s);
    return;
  }

  for (int i = visited.empty() ? 0 : visited.back() + 1; i < m; ++i) {
    visited.push_back(i);
    solve(T + 1, visited);
    visited.pop_back();
  }
}

int main(int argc, char *argv[]) {
  int i, j;
  n = readInt();
  m = readInt();
  for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) a[i][j] = readInt();
  vector <int> visited;
  solve(0, visited);
  return !printf("%d\n", mx);
}