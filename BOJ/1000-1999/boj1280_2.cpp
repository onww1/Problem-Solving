#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 2e5;
const int MOD = 1e9 + 7;

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
  scanf("%d %d", &n, &a);
  update(tree_val, a + 1, a);
  update(tree_cnt, a + 1, 1);

  for (i = 1; i < n; ++i) {
    scanf("%d", &a);
    ll val = ((sum(tree_val, MAX + 1) - sum(tree_val, a + 1)) - (sum(tree_cnt, MAX + 1) - sum(tree_cnt, a + 1)) * a) % MOD;
    val = (sum(tree_cnt, a) * a - sum(tree_val, a) + val) % MOD;
    ans = (1LL * ans * val) % MOD;
    update(tree_val, a + 1, a);
    update(tree_cnt, a + 1, 1);
  }
  return !printf("%d\n", ans);
}