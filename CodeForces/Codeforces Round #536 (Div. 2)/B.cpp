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

struct dish {
  ll a, c;
  int i;
};

bool operator< (dish a, dish b) {
  if (a.c == b.c) return a.i > b.i;
  return a.c > b.c;
}

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

dish dishs[100050];
priority_queue <dish> pq;
int main(int argc, char *argv[]) {
  int n, m, i, j;
  ll t, d;
  n = readInt(), m = readInt();
  for (i = 1; i <= n; ++i) dishs[i].a = readLongLong(), dishs[i].i = i;
  for (i = 1; i <= n; ++i) dishs[i].c = readLongLong(), pq.push(dishs[i]);
  
  for (i = 0; i < m; ++i) {
    t = readLongLong();
    d = readLongLong();
    ll sum = 0LL;
    while (d > 0) {
      if (dishs[t].a > 0LL) {
        if (dishs[t].a > d) {
          dishs[t].a -= d;
          sum += dishs[t].c * d;
          d = 0;
        } else {
          sum += dishs[t].c * dishs[t].a;
          d -= dishs[t].a;
          dishs[t].a = 0;
        }
      } else if (!pq.empty()) {
        dish di = pq.top();
        pq.pop();

        if (dishs[di.i].a > d) {
          dishs[di.i].a -= d;
          sum += dishs[di.i].c * d;
          d = 0;
        } else {
          sum += dishs[di.i].c * dishs[di.i].a;
          d -= dishs[di.i].a;
          dishs[di.i].a = 0;
        }

        if (dishs[di.i].a > 0) pq.push(dishs[di.i]);
      } else {
        sum = 0;
        break;
      }
    }
    printf("%lld\n", sum);
  }
  return 0;
}