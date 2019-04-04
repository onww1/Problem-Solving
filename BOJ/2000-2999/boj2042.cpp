#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1 << 20;

ll a[MAX], tree[2 * MAX], n, m, k;

ll make_tree(int node, int start, int end) {
  if (start == end) return tree[node] = a[start];
  int mid = (start + end) / 2;
  return tree[node] = make_tree(node * 2, start, mid)
                    + make_tree(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, ll diff) {
  if (idx < start || idx > end) return;
  tree[node] += diff;
  if (start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
}

ll sum(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return 0LL;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char *argv[]) {
  scanf("%lld %lld %lld", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%lld", a + i);
  make_tree(1, 0, n-1);
  m += k;
  int x, y; ll z;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %lld", &x, &y, &z);
    if (x == 1) {
      update(1, 0, n-1, y-1, z - a[y-1]);
      a[y-1] = z;
    } else {
      printf("%lld\n", sum(1, 0, n-1, y-1, z-1));
    }
  }
  return 0;
}
