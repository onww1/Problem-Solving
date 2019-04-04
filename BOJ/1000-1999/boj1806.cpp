#include <cstdio>
#include <algorithm>
using namespace std;

char buf[1 << 17];

inline char read() {
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}

inline int readInt() {
  int sum = 0;
  char now = read();

  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') {
    sum = sum * 10 + now - '0';
    now = read();
  }
  return sum;
}

int a[100050];
int main(int argc, char *argv[]) {
  int n, s, i, l, r, sum, mn = 0x7f7f7f7f;
  n = readInt();
  s = readInt();
  for (i = 0; i < n; ++i) a[i] = readInt();
  l = 0, r = 1, sum = a[0];
  while (r <= n && l < r) {
    if (sum >= s) {
      mn = min(mn, r - l);
      sum -= a[l++];
    } else {
      sum += a[r++];
    }
  }
  return !printf("%d\n", mn == 0x7f7f7f7f ? 0 : mn);
}