#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flag ? sum : -sum;
}
inline int readLongLong() {
  ll sum = 0;
  int flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10LL + now - '0', now = read();
  return flag ? sum : -sum;
}

int a[300050];
int main(int argc, char *argv[]) {
  int n, i, j;
  ll sum = 0LL;
  n = readInt();
  for (i = 0; i < n; ++i) a[i] = readInt();
  sort(a, a + n);
  for (i = 0; i < n/2; ++i) sum += ((a[i] + a[n - 1 - i]) * (a[i] + a[n - 1 - i]));
  return !printf("%lld\n", sum);
}