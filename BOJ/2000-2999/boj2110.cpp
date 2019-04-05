#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2e5;
int n, c, a[MAX];

char buf[1 << 18];
inline char read() {
  static int idx = 1 << 18;
  if (idx == 1 << 18) {
    int nidx = fread(buf, 1, 1 << 18, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0, flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flag ? sum : -sum;
}

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
  n = readInt(), c = readInt();
  for (int i = 0; i < n; ++i) a[i] = readInt();
  sort(a, a + n);
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  puts("");

  int s = 0, e = 1e9, m;
  while (s < e) {
    m = (s + e) / 2;
    if (solve(0, m, c - 1)) s = m + 1;
    else e = m;
  }
  return !printf("%d\n", solve(0, s, c - 1) ? s : s - 1);
}