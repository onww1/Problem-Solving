#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int SZ = 1 << 19;
const int MAX = 5e5;
int N, M, P, od, idx[MAX + 1], cn[MAX + 1], A[SZ], tree[2 * SZ], lazy[2 * SZ];
vector <int> edges[MAX + 1];

int dfs(int node) {
  idx[node] = ++od;

  int cnt = 0;
  for (int next : edges[node]) 
    cnt += dfs(next);
  
  cn[node] = cnt;
  return cnt + 1;
}

void update_lazy(int node, int start, int end) {
  if (lazy[node] == 0) return;
  tree[node] += (end - start + 1) * lazy[node];
  if (start != end) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int diff) {
  update_lazy(node, start, end);
  
  if (end < left || right < start) return;
  if (left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if (start != end) {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
    return;
  }

  int mid = (start + end) / 2;
  update_range(node * 2, start, mid, left, right, diff);
  update_range(node * 2 + 1, mid + 1, end, left, right, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get_val(int node, int start, int end, int idx) {
  update_lazy(node, start, end);

  if (idx < start || end < idx) return 0;
  if (start == end) return tree[node];

  int mid = (start + end) / 2;
  return get_val(node * 2, start, mid, idx) + get_val(node * 2 + 1, mid + 1, end, idx);
}

int main(int argc, char *argv[]) {
  scanf("%d %d %d", &N, &M, A + 1);
  for (int i = 2; i <= N; ++i) {
    scanf("%d %d", A + i, &P);
    edges[P].push_back(i);
  }

  dfs(1);

  for (int i = 1; i <= N; ++i) 
    update_range(1, 1, N, idx[i], idx[i], A[i]);

  char c; int a, x;
  for (int i = 0; i < M; ++i) {
    scanf(" %c %d", &c, &a);
    if (c == 'p') {
      scanf("%d", &x);
      update_range(1, 1, N, idx[a] + 1, idx[a] + cn[a], x);
    } else {
      printf("%d\n", get_val(1, 1, N, idx[a]));
    }
  }
  
  return 0;
}