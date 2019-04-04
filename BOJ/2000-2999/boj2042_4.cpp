#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e6;

char buf[1 << 18];
inline char read() {
  static int idx = 1 << 18;
  if (idx == 1 << 18) {
    int nidx = fread(buf, 1, 1 << 18, stdin);
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
  return sum;
}
inline ll readLL() {
  ll sum = 0, flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

ll a[MAX + 1], tree[MAX + 1], n, m, k;

void update(int node, ll diff) {
  while (node <= n) {
    tree[node] += diff;
    node += node & -node;
  }
}

ll sum(int node) {
  ll ret = 0LL;
  while (node > 0) {
    ret += tree[node];
    node -= node & -node;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  n = readLL(), m = readLL(), k = readLL();
  m += k;
  for (int i = 1; i <= n; ++i) {
    a[i] = readLL();
    update(i, a[i]);
  }

  int x, y; ll z;
  while (m--) {
    x = readInt(), y = readInt(), z = readLL();
    if (x == 1) {
      update(y, z - a[y]);
      a[y] = z;
    } else {
      printf("%lld\n", sum(z) - sum(y-1));
    }
  }
  return 0;
}