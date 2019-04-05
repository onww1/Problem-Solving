#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 3e5;

const int BS = 1 << 17;
char buf[BS];
inline char read() {
  static int idx = BS;
  if (idx == BS) {
    int nidx = fread(buf, 1, BS, stdin);
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

int a[MAX + 1];
int main(int argc, char *argv[]) {
  int n, i;
  n = readInt();
  for (i = 0; i < n; ++i) a[readInt()] = i + 1;
  for (i = n - 1; i > 0; --i) if (a[i] > a[i + 1]) break;
  return !printf("%d\n", i);
}