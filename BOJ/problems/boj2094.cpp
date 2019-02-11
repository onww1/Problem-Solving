#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

const int INF = 0x7f7f7f7f;
const int SZ = 1 << 16;
int A[SZ], idx[SZ], tree[SZ * 2], n, m;

int init(int node, int start, int end) {
  if (start == end) return tree[node] = A[start];
  int mid = (start + end) / 2;
  return tree[node] = max(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int get_max(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return 0;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return max(get_max(node * 2, start, mid, left, right),
             get_max(node * 2 + 1, mid + 1, end, left, right));
}

int main(int argc, char *argv[]) {
  int x, y, x_idx, y_idx, i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d %d", &x, &y);
    idx[i] = x;
    A[i] = y;
  }

  init(1, 1, n);

  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d %d", &x, &y);
    x_idx = lower_bound(idx + 1, idx + n + 1, x) - idx; 
    if (x_idx == n + 1 || idx[x_idx] != x) x_idx--;
    y_idx = lower_bound(idx + 1, idx + n + 1, y) - idx;
    int mx = get_max(1, 1, n, x_idx + 1, y_idx - 1);
    
    bool x_info = !(x_idx == -1 || idx[x_idx] != x);
    bool y_info = !(y_idx == n + 1 || idx[y_idx] != y);
    
    if (x_info && y_info && A[x_idx] >= A[y_idx] && mx < A[y_idx]) 
      printf("%s\n", y - x == y_idx - x_idx ? "true" : "maybe");
    else if ((y_info && mx >= A[y_idx]) || 
             (x_info && mx >= A[x_idx]) || 
             (x_info && y_info && A[x_idx] < A[y_idx]))
      printf("false\n");
    else printf("maybe\n");
  }
  return 0;
}