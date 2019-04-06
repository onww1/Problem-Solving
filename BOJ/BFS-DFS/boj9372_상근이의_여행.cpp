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
  int t, n, m, a, b;
  t = readInt();
  while (t--) {
    n = readInt();
    m = readInt();
    while (m--) {
      a = readInt();
      b = readInt();
    }
    printf("%d\n", n-1);
  }
  return 0;
}