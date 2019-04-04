#include <cstdio>
typedef long long ll;
const int MAX = 1e5;

ll A[MAX + 1], tree[MAX + 1], n, q;

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

void update(int node, ll diff) {
  while (node <= n) {
    tree[node] += diff;
    node += node & -node;
  }
}

ll sum(int node) {
  ll ret = 0;
  while (node > 0) {
    ret += tree[node];
    node -= node & -node;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int i, j, x, y, a, b;
  scanf("%lld %lld", &n, &q);
  for (i = 1; i <= n; ++i) {
    scanf("%lld", A + i);
    update(i, A[i]);
  }

  while (q--) {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    if (x > y) swap(x, y);
    printf("%lld\n", sum(y) - sum(x-1));
    update(a, (ll)b - A[a]);
    A[a] = b;
  }
  return 0;
}