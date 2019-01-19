#include <cstdio>
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

int main(int argc, char *argv[]) {
  int t, m, n, i, j, s, map[100][100], cnt[100];
  t = readInt();
  while (t--) {
    m = readInt();
    n = readInt();
    s = 0;
    for (i = 0; i < m; ++i) for (j = 0; j < n; ++j) map[i][j] = readInt();
    for (i = 0; i < n; ++i) cnt[i] = 0;
    for (i = m-1; i >= 0; --i) {
      for (j = 0; j < n; ++j) {
        if (map[i][j] == 1) {
          s += (m - 1 - cnt[j] - i);
          ++cnt[j];
        }
      }
    }
    printf("%d\n", s);
  }
  return 0;
}