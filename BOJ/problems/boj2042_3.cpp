#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e6;

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
  scanf("%lld %lld %lld", &n, &m, &k); m += k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    update(i, a[i]);
  }

  int x, y; ll z;
  while (m--) {
    scanf("%d %d %lld", &x, &y, &z);
    if (x == 1) {
      update(y, z - a[y]);
      a[y] = z;
    } else {
      printf("%lld\n", sum(z) - sum(y-1));
    }
  }
  return 0;
}