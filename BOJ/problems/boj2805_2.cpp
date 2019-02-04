#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
int n, m, h[MAX];

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

bool solve(int height) {
  ll sum = 0LL;
  for (int i = 0; i < n; ++i) 
    if (h[i] > height) sum += (h[i] - height);
  return sum >= m;
}

int main(int argc, char *argv[]) {
  n = readInt(), m = readInt();
  for (int i = 0; i < n; ++i) h[i] = readInt();
  
  int s = 0, e = 1e9 + 1, m;
  while (s < e) {
    m = (s + e) >> 1;
    if (solve(m)) s = m + 1;
    else e = m;
  }
  return !printf("%d\n", solve(s) ? s : s - 1);
}