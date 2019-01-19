#include <cstdio>
using namespace std;

int c[20000001];
const int offset = 10000000;
char buf[1<<17];

inline char read()
{
  static int idx = 1 << 17;
  if (idx == 1<<17)
  {
    int nidx = fread(buf, 1, 1<<17, stdin);
	  if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}

inline int readInt()
{
  int sum = 0;
  bool minus = false;
  char now = read();
  
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') minus = true, now = read();
  while (now >= '0' && now <= '9')
  {
      sum = sum*10 + now-48;
      now = read();
  }
  if (minus) sum *= -1;
  return sum;
}

int main(int argc, char *argv[]) {
  int n, m, a, i;
  n = readInt();
  for (i = 0; i < n; ++i) {
    a = readInt();
    ++c[a + offset];
  }
  m = readInt();
  for (i = 0; i < m; ++i) {
    a = readInt();
    printf("%d ", c[a + offset]);
  }
  return !printf("\n");
}