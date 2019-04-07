#include <cstdio>
const int MAX = 1e6;

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

int arr[MAX + 1];
int main(int argc, char *argv[]) {
  int n, a, i, idx;
  bool f = true, b = true;
  n = readInt();
  for (i = 0; i < n; ++i) {
    a = readInt();
    arr[a] = i;
  }
  a = readInt(); idx = arr[a];
  for (i = 1; i < n; ++i) {
    a = readInt();
    if (arr[a] != (idx + n - 1) % n) b = false;
    if (arr[a] != (idx + 1) % n) f = false;
    idx = arr[a];
  }
  if (!f && !b) return !printf("bad puzzle\n");
  return !printf("good puzzle\n");
}