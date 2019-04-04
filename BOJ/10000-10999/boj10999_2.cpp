#include <cstdio>
typedef long long ll;
const int SZ = 1 << 20;
ll a[SZ], tree[2 * SZ], lazy[2 * SZ];

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
  return flag ? sum : -sum;
}
inline ll readLL() {
  ll sum = 0, flag = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flag = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flag ? sum : -sum;
}

void lazy_update(int node, int start, int end) {
  if (lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_range(int node, int start, int end, int left, int right, ll diff) {
  lazy_update(node, start, end);
  if (end < left || right < start) return;
  if (left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if (start != end) {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
  } else {
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = a[start];
  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) +
                      init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
  lazy_update(node, start, end);
  if (end < left || right < start) return 0LL;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + 
         sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char *argv[]) {
  int n, m, k, i, x, y, z; ll w;
  n = readInt(), m = readInt(), k = readInt(); 
  m += k;
  for (i = 0; i < n; ++i) a[i] = readLL();
  init(1, 0, n-1);
  while (m--) {
    x = readInt(), y = readInt(), z = readInt();
    if (x == 1) {
      w = readLL();
      update_range(1, 0, n-1, y-1, z-1, w);
    } else {
      printf("%lld\n", sum(1, 0, n-1, y-1, z-1));
    }
  }
  return 0;
}