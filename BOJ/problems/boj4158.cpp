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
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

int a[1000050], b[1000050];
int main(int argc, char *argv[]) {
  int n, m, i, j, cnt;
  while (1) {
    n = readInt(), m = readInt();
    if (!n && !m) break;
    for (i = 0; i < n; ++i) a[i] = readInt();
    for (i = 0; i < m; ++i) b[i] = readInt();
    i = j = cnt = 0; 
    while (i < n && j < m) {
      if (a[i] == b[j]) ++cnt, ++i, ++j;
      else if (a[i] > b[j]) ++j;
      else ++i;
    }
    printf("%d\n", cnt);
  }
  return 0;
}