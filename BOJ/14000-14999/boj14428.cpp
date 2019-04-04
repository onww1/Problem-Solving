#include <cstdio>
#include <algorithm>
using namespace std;

const int BUFFER_SIZE = 1 << 17;
char buf[BUFFER_SIZE];
inline char read() {
  static int idx = BUFFER_SIZE;
  if (idx == BUFFER_SIZE) {
    int nidx = fread(buf, 1, BUFFER_SIZE, stdin);
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

typedef pair<int,int> pii;
const int INF = 0x7fffffff;
const int SZ = 1 << 17;
int a[SZ]; pii tree[2 * SZ];

pii init(int node, int start, int end) {
  if (start == end) return tree[node] = { a[start], start };
  int mid = (start + end) / 2;
  return tree[node] = min(init(node * 2, start, mid),
                          init(node * 2 + 1, mid + 1, end));
}

void update(int node, int start, int end, int idx, int val) {
  if (idx < start || end < idx) return;
  if (start == end) { tree[node] = {val, idx}; return; }
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, val);
  update(node * 2 + 1, mid + 1, end, idx, val);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

pii get_min(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return {INF, INF};
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return min(get_min(node * 2, start, mid, left, right),
             get_min(node * 2 + 1, mid + 1, end, left, right));
}

int main(int argc, char *argv[]) {
  int n, i;
  n = readInt();
  for (i = 1; i <= n; ++i) a[i] = readInt();
  init(1, 1, n);
  
  int m, x, y, z;
  m = readInt();
  while (m--) {
    x = readInt();
    y = readInt();
    z = readInt();
    if (x == 1) {
      update(1, 1, n, y, z);
      a[y] = z;
    } else {
      printf("%d\n", get_min(1, 1, n, y, z).second);
    }
  }
  return 0;
}