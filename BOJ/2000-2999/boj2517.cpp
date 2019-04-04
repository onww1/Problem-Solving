#include <cstdio>
#include <vector>
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
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

void update(int node, int diff);
int sum(int node);

int tree[100050];
vector <int> table[100050];
int main(int argc, char *argv[]) {
  int n, a, i, t;
  n = readInt();
  for (i = 0; i < n; ++i) {
    a = readInt();
    t = (a - 1) / 100000;
    int l = 0, r = table[t].size(), m;
    while (l < r) {
      m = (l + r) / 2;
      if (table[t][m] < a) l = m + 1;
      else r = m;
    }
    printf("%d\n", i + 1 - sum(t) - r);
    table[t].insert(table[t].begin() + r, a);
    update(t + 1, 1);
  }
  return 0;
}

void update(int node, int diff) {
  while (node <= 100000) {
    tree[node] += diff;
    node += (node & -node);
  }
}

int sum(int node) {
  int s = 0;
  while (node > 0) {
    s += tree[node];
    node -= (node & -node);
  }
  return s;
}