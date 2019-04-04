#include <cstdio>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
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

pii books[MAX];
int main(int argc, char *argv[]) {
  int n, i;
  n = readInt();
  for (i = 0; i < n; ++i) {
    books[i].X = readInt();
    books[i].Y = i + 1;
  }
  sort(books, books + n);
  for (i = n-1; i > 0; --i) {
    if (books[i].Y < books[i-1].Y) 
      return !printf("%d\n", i);
  }
  return !printf("0\n");
}