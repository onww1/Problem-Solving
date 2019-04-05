#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 500;
vector <int> edges[MAX + 1];
int pa[MAX + 1], valid[MAX + 1], N, M;

int _find(int a) {
  if (pa[a] < 0) return a;
  return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
  int a_root = _find(a);
  int b_root = _find(b);
  if (a_root == b_root) return;

  valid[a_root] = valid[b_root] = min(valid[a_root], valid[b_root]);
  pa[b_root] = a_root;
}

int main(int argc, char *argv[]) {
  for (int test_case = 1; ; ++test_case) {
    scanf("%d %d", &N, &M);
    if (!N && !M) break;

    for (int i = 1; i <= N; ++i) {
      edges[i].clear();
      pa[i] = -1;
      valid[i] = 1;
    }

    int u, v;
    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &u, &v);
      int a_root = _find(u);
      int b_root = _find(v);
      if (a_root == b_root) valid[a_root] = 0;
      else _union(u, v);
    }

    set <int> s;
    for (int i = 1; i <= N; ++i) {
      int group = _find(i);
      if (valid[group]) s.insert(group);
    }

    if (s.size() == 0) printf("Case %d: No trees.\n", test_case);
    else if (s.size() == 1) printf("Case %d: There is one tree.\n", test_case);
    else printf("Case %d: A forest of %lu trees.\n", test_case, s.size());
  }
  return 0;
}