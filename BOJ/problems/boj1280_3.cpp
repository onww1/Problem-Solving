#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 2e5;
const int MOD = 1e9 + 7;

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
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

ll tree_val[MAX + 2], tree_cnt[MAX + 2];

void update(ll *tree, int node, ll diff) {
  while (node <= MAX + 1) {
    tree[node] += diff;
    node += node & -node;
  }
}

ll sum(ll *tree, int node) {
  ll ret = 0LL;
  while (node > 0) {
    ret += tree[node];
    node -= node & -node;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n, a, i, ans = 1LL;
  n = readInt(), a = readInt();
  update(tree_val, a + 1, a);
  update(tree_cnt, a + 1, 1);

  for (i = 1; i < n; ++i) {
    a = readInt();
    ll val = ((sum(tree_val, MAX + 1) - sum(tree_val, a + 1)) - (sum(tree_cnt, MAX + 1) - sum(tree_cnt, a + 1)) * a) % MOD;
    val = (sum(tree_cnt, a) * a - sum(tree_val, a) + val) % MOD;
    ans = (1LL * ans * val) % MOD;
    update(tree_val, a + 1, a);
    update(tree_cnt, a + 1, 1);
  }
  return !printf("%d\n", ans);
}
