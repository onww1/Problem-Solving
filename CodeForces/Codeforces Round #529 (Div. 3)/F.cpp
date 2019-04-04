#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

struct offer { 
  int u, v; 
  ll w;
};

bool operator<(offer a, offer b) {
  return a.w > b.w;
}

int pa[200001];
ll a[200001];

int find_(int a) {
  if (pa[a] < 0) return a;
  else return pa[a] = find_(pa[a]);
}

void union_(int a, int b) {
  int x = find_(a);
  int y = find_(b);
  if (x == y) return;
  pa[x] = y;
}

int main(int argc, char *argv[]) {
  int n, m, x, y, i, idx = 1;
  ll w, ans = 0;
  priority_queue<offer> pq;

  scanf("%d %d", &n, &m);
  memset(pa, -1, sizeof(int) * (n + 1));
  for (i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    if (a[idx] > a[i]) idx = i;
  }

  for (i = 1; i <= n; ++i) {
    if (i != idx) pq.push({idx, i, a[i] + a[idx]});
  }

  for (i = 0; i < m; ++i) {
    scanf("%d %d %lld", &x, &y, &w);
    pq.push({x, y, w});
  }

  for (i = 0; i < n-1; ) {
    x = pq.top().u;
    y = pq.top().v;
    w = pq.top().w;
    pq.pop();

    if (find_(x) != find_(y)) {
      ++i;
      ans += w;
      union_(x, y);
    }
  }

  printf("%lld\n", ans);
  return 0;
}