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

int a[1025][1025];
int main(int argc, char *argv[]) {
  int n, m, i, j, x1, y1, x2, y2;
  n = readInt();
  m = readInt();
  for (i = 1; i <= n; ++i) for (j = 1; j <= n; ++j) 
    a[i][j] = readInt() + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
  for (i = 0; i < m; ++i) {
    x1 = readInt(); y1 = readInt();
    x2 = readInt(); y2 = readInt();
    printf("%d\n", a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1]);
  }
  return 0;
}