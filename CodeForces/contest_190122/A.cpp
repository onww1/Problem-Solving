#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
  int sum = 0, flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = -1, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}
inline int readLongLong() {
  ll sum = 0;
  int flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = -1, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10LL + now - '0', now = read();
  return sum;
}

int main(int argc, char *argv[]) {
  int n, k, i, j;
  n = readInt();
  for (i = 9; i > 0; --i) {
    if (n % i == 0) {
      printf("%d\n", n/i);
      for (j = 0; j < n/i; ++j) printf("%d ", i);
      return 0;
    }
  }
  if (n > 9) {
    printf("%d\n", n/9 + 1);
    for (i = 0; i < n/9; ++i) printf("%d ", 9);
    printf("%d\n", n%9);
  } else {
    printf("%d\n", n);
  }
  return 0;
}